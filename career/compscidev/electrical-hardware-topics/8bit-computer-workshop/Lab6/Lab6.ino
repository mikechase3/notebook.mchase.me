// BE Bus Enable. Set high for normal operation.
const char BE = 40; // OUTPUT ONLY
// PHI2 the clock.
const char CLOCK=41;
const char CLOCKLED=4;
//RWB Read-Write bit. When high, the CPU is reading data. 
const char RWB = 42;   // INPUT ONLY
//RESB When low for 2+ cycles, the CPU is reset and PC is set to FFFC-D.
const char RESET = 43;  // OUTPUT ONLY
//VPB vector pull. When low, the CPU is reading the interrupt vector .
const char VPB = 44;  // INPUT ONLY
//RDY READY. When low, the CPU will stop. Keep high for normal operation.
const char RDY = 45;  // OUTPUT
//IRQB Interrupt Request. Low will trigger an interrupt.
const char IRQB = 46; // OUTPUT ONLY
//NMIB Non Maskable Interrupt. Low will trigger an interrupt.
const char NMIB = 47; // OUTPUT ONLY
// Synchronize OpCode fetch. Goes high when CPU is fetching an op code. 
const char SYNC = 48; // INPUT ONLY


// special addresses
const uint16_t RESET_ADDRESS_LB = 0xFFFC;
const uint16_t RESET_ADDRESS_HB = 0xFFFD;
const uint8_t RESET_VECTOR_LB = 0x00;
const uint8_t RESET_VECTOR_HB = 0x80;


//global vars to track state...
bool clockState = false;  //false==clock low    true==clock high.
uint8_t RWB_status = LOW;
uint8_t VPB_status = HIGH;
uint8_t SYNC_status = HIGH;
uint16_t address = 0x00;
uint8_t data = 0x00;

// UART sim
const uint16_t UART_Data_addr = 0x5000;
const uint16_t UART_Status_addr = 0x5001;
const uint16_t UART_Cmd_addr = 0x5002;
const uint16_t UART_Ctrl_addr = 0x5003;
uint8_t UART_Data_read = 0;
uint8_t UART_Data_write = 0;
// set the status to transmit data register to 1, which means empty. 
uint8_t UART_Status = B00010000; //0==parity error, 1==framing error, 2==overrun error, 3==receiver data register full, 4==transmitter data register empty, 5==data carrier detect, 6==data set ready, 7==interrupt
uint8_t UART_Cmd = 0;
uint8_t UART_Ctrl = 0;
int serialinput = 0;
static void UART_Set_Receive_Register_Full( void ) { UART_Status = UART_Status | B00001000; }
static void UART_Reset_Receive_Register_Full( void ) { UART_Status = UART_Status & B11110111; }
static bool UART_Get_Receive_Register_Full(void) { return (UART_Status & B00001000) > 0; }


// use internal clock, (a potentiometer connected to analog input 7, and a N-O button connected to digital input 7)
const char analogClockSpeedPin = A7;  // center pin of potentiometer
const char stepClockButtonPin = 6;   // button that steps the clock
int analogClockSpeed = 0;
unsigned long clockDelayInMs = 0;
unsigned long clockFlopStart = 0;
unsigned int superFastCounter = 0;
const unsigned int SuperFastCounterResetValue = 0x8FFF;
const unsigned int SuperFastThreshold = 0x0014;

const uint16_t ROM_SIZE = 0x1800; //6KB
uint8_t rom_bank = 1;  // rom bank, 1-6
byte ROM[ROM_SIZE];

void setup() {
  SetAddressPinsToInput();
  SetDataPinsToInput();

  //set Bus Enable to high. If set to low, address and data go HI-Z
  pinMode(BE, OUTPUT);
  digitalWrite(BE, HIGH);

  //when Read-Write is high, the processor is reading data. When low, writing data.
  pinMode(RWB, INPUT);

  pinMode(RESET, OUTPUT);
  digitalWrite(RESET, HIGH);

  // interrupt Vector Pull
  pinMode(VPB, INPUT);
  
  // Ready
  pinMode(RDY, OUTPUT);
  digitalWrite(RDY, HIGH);

  // interrupt request
  pinMode(IRQB, OUTPUT);
  digitalWrite(IRQB, HIGH);
  // non-maskable interrupt request
  pinMode(NMIB, OUTPUT);
  digitalWrite(NMIB, HIGH);
  // op code fetch Sync
  pinMode(SYNC, INPUT);


  //initialize internal clock
  pinMode(CLOCK, OUTPUT);
  pinMode(CLOCKLED, OUTPUT);
  digitalWrite(CLOCK, LOW);
    digitalWrite(CLOCKLED, LOW);
  pinMode(stepClockButtonPin, INPUT);
  clockFlopStart = millis();

  Serial.begin(57600);
  Serial.println("Emulator started.");

  int analogClockSpeed = analogRead(analogClockSpeedPin);
  Serial.print("analogClockSpeed   ");
  Serial.println(analogClockSpeed);
  if (analogClockSpeed < SuperFastThreshold) {
    superFastCounter = SuperFastCounterResetValue;
  }

  FillRom1(ROM);
  rom_bank = 1;

  ResetCPU();
  Serial.println("In your terminal, be sure to set `Implicit CR in every LF`.");
  Serial.println("To start BASIC, enter `A333` <enter> ");
  Serial.println("That should show an `A2` at memory location A333.");
  Serial.println("Then enter `R` <enter> to start running it.");
  Serial.println("At the memory prompt, enter `16000` <enter> ");
  Serial.println("At the terminal prompt, enter `40` <enter> ");
}

void loop() {
  
  if (clockState) {
    WaitForClockLow();
  }
  else {
    WaitForClockHigh();
  }


  if (RWB_status == HIGH) { // The CPU is reading
    if (address <= 0x3FFF) {  //RAM
      ReadDataLines();
    }
    else if (address <= 0x5FFF) { // UART
      if (address == UART_Data_addr) {
        WriteDataLines(UART_Data_read);
        UART_Reset_Receive_Register_Full();
        //Serial.println("");
        //Serial.println("Receive register full reset.");
      }
      else if (address == UART_Status_addr) {
        WriteDataLines(UART_Status);
      }
      else if (address == UART_Cmd_addr) {
        WriteDataLines(UART_Cmd);
      }
      else if (address == UART_Ctrl_addr) {
        WriteDataLines(UART_Ctrl);
      }
      else {
        WriteDataLines(0);
      }
    }
    else if (address >= 0x8000) {  //ROM
      WriteDataLines(GetDataFromRom());
    }
  }
  else {   // The CPU is writing data from the CPU to either memory or IO 
    ReadDataLines(); 
    if (address <= 0x7FFF && clockState) {  
      if (address >= 0x6000) {    // writing to VIA
      }
      else if (address >= 0x5000) {   // writing to UART
        if (address == UART_Data_addr) {
          UART_Data_write = data;          //There's not really a reason to write the data to the global variable... get rid of it???
          Serial.print((char)UART_Data_write);
          // we don't need to update the status register since we are always immediately writing the value.
        }
        else if (address == UART_Status_addr) {  // You only write to the status register to reset the UART chip...
          UART_Status = B00010000;
        }
        else if (address == UART_Cmd_addr) {  // we don't care about this either yet
          UART_Cmd = data;
        }
        else if (address == UART_Ctrl_addr) {  // we don't care what's written here yet.
          UART_Ctrl = data;
        }
      }
    }
  }

  if (Serial.available() && !UART_Get_Receive_Register_Full()) {
    serialinput = Serial.read();
    UART_Data_read = (uint8_t) (serialinput & 0b0000000011111111);
    UART_Set_Receive_Register_Full();
  }

  //if (clockState && superFastCounter == 0) {
  //  DumpData();
  //}
}

uint8_t GetDataFromRom() {
  if (address <= 0x97FF ) {
    if (rom_bank != 1) {
      FillRom1(ROM);
      rom_bank = 1;
    }
    uint16_t romaddress = address & 0x7FFF;
    return ROM[romaddress];
  }
  else if (address <= 0xAFFF) {
    if (rom_bank != 2) {
      FillRom2(ROM);
      rom_bank = 2;
    }
    uint16_t romaddress = (address & 0x7FFF) - 0x1800;
    return ROM[romaddress];
  }
  else if (address <= 0xC7FF) {
    if (rom_bank != 3) {
      FillRom3(ROM);
      rom_bank = 3;
    }
    uint16_t romaddress = (address & 0x7FFF) - 0x3000;
    return ROM[romaddress];
  }
  else if (address <= 0xDFFF) {
    if (rom_bank != 4) {
      FillRom4(ROM);
      rom_bank = 4;
    }
    uint16_t romaddress = (address & 0x7FFF) - 0x4800;
    return ROM[romaddress];
  }
  else if (address <= 0xF7FF) {
    if (rom_bank != 5) {
      FillRom5(ROM);
      rom_bank = 5;
    }
    uint16_t romaddress = (address & 0x7FFF) - 0x6000;
    return ROM[romaddress];
  }
  else {
    if (rom_bank != 6) {
      FillRom6(ROM);
      rom_bank = 6;
    }
    uint16_t romaddress = (address & 0x7FFF) - 0x7800;
    return ROM[romaddress];
  }
}

void ResetCPU() {
  Serial.println("Resetting CPU.... make sure clock is running...");
  digitalWrite(RESET, LOW);

  WaitForClockLow();
  WaitForClockHigh();
  WaitForClockLow();
  WaitForClockHigh();
  Serial.println("Resetting: 2 more clock cycles");
  WaitForClockLow();
  WaitForClockHigh();
  Serial.println("Resetting: 1 more clock cycle");
  WaitForClockLow();
  WaitForClockHigh();

  digitalWrite(RESET, HIGH);

  Serial.println(" Keep the clock running....");

  for (int i=25; i>=0; i--)
  {
    if (clockState) {
      WaitForClockLow();
    }
    else {
      WaitForClockHigh();
    }
    
    if (VPB_status == LOW) {
      if (address == RESET_ADDRESS_LB) {
        if (clockState) { Serial.println("Reset address LB"); }
        WriteDataLines(RESET_VECTOR_LB);
      }
      else if (address == RESET_ADDRESS_HB) {
        if (clockState) { Serial.println("Reset address HB"); }
        WriteDataLines(RESET_VECTOR_HB);
        i=1;
      }
      else {
        Serial.println("This should never happen....");
      }
    }
    //if (clockState) {
    //  DumpData();
    //}
  }
  
  WaitForClockLow();
  SetDataPinsToInput();
  Serial.println("Reset complete.");
}


void DumpData() {
  //Serial.print(" analogClockSpeed:  ");
  //Serial.print(analogClockSpeed);
  //Serial.print("    ");
  //Serial.print(superFastCounter);
  Serial.print("   CLOCK:");
  Serial.print(clockState);
  Serial.print("   RWB=");
  Serial.print(RWB_status == HIGH ? "READ " : "WRITE");
  Serial.print("  VPB=");
  Serial.print(VPB_status == HIGH ? "_________" : "INTERRUPT");
  Serial.print("  SYNC=");
  Serial.print(SYNC_status == HIGH ? "OP FETCH   " : "_______    ");
  if (address <= 0x3FFF) {
    Serial.print("     RAM ");  
  }
  // else if (address <= 0x4FFF) {
  //   Serial.print(" INVALID ");
  // }
  else if (address <= 0x5FFF) {
    Serial.print("    UART ");
  }
  // else if (address <= 0x7FFF) {
  //   Serial.print("      IO ");
  // }
  else if (address >= 0x8000) {
   Serial.print("     ROM ");
  } 
  Serial.print(" ADDRESS=");
  Serial.print(address,HEX);
  Serial.print("   data=");
  Serial.println(data,HEX);
}

void checkInternalClock() {

  if (superFastCounter > 0) {
    superFastCounter--;
    if (superFastCounter <= 5000) {  // blink the LED twice to indicate it's in superfast mode.
      if (superFastCounter == 5000) {
        digitalWrite(CLOCKLED, HIGH);
      }
      else if (superFastCounter == 3000) {
        digitalWrite(CLOCKLED, LOW);
      }
      else if (superFastCounter == 2000) {
        digitalWrite(CLOCKLED, HIGH);
      }
      else if (superFastCounter == 10) {
        digitalWrite(CLOCKLED, LOW);
      }
    }
    flopTheClock();
    if (superFastCounter == 0) {
      int newAnalogClockSpeed = analogRead(analogClockSpeedPin);
      if (newAnalogClockSpeed < SuperFastThreshold) {
        superFastCounter = SuperFastCounterResetValue;
      }
    }
    return;
  }


  unsigned long timediff = (millis() - clockFlopStart);
  int newAnalogClockSpeed = analogRead(analogClockSpeedPin);
  if (newAnalogClockSpeed > 1000) {  //clock is off... 
    if (analogClockSpeed < 1000) {
      digitalWrite(CLOCKLED, 0);
      delay(100);
    }
    char hilow = digitalRead(stepClockButtonPin);
    analogClockSpeed = newAnalogClockSpeed;
    if (timediff > 50 && hilow != clockState) {  // we are making sure 100ms has passed because we have to de-bounce the input.
      flopTheClock();
      digitalWrite(CLOCKLED, clockState);
    }
  }
  else {
    if (abs(newAnalogClockSpeed - analogClockSpeed) > 5) { //it has changed!
      analogClockSpeed = newAnalogClockSpeed;
      if (analogClockSpeed < SuperFastThreshold) {
        clockDelayInMs = 0;
        superFastCounter = SuperFastCounterResetValue;
      }
      else if (analogClockSpeed < 200) {
        clockDelayInMs = 0;
      }
      else if (analogClockSpeed < 400) {
        clockDelayInMs = analogClockSpeed >> 3;
      }
      else if (analogClockSpeed < 600) {
        clockDelayInMs = analogClockSpeed >> 2;
      }
      else if (analogClockSpeed < 800) {
        clockDelayInMs = analogClockSpeed >> 1;
      }
      else {
        clockDelayInMs = analogClockSpeed;
      }
    }
    if (timediff > clockDelayInMs) {
      char hilow = digitalRead(stepClockButtonPin);
      if (!hilow) {
        flopTheClock();
        digitalWrite(CLOCKLED, clockState);
      }
    }
  }
}

void flopTheClock() {
  clockState = !clockState;
  digitalWrite(CLOCK, clockState);
  clockFlopStart = millis();
}

void WaitForClockLow() {
  while (clockState) {
    checkInternalClock();
  }
  RWB_status = digitalRead(RWB);
  VPB_status = digitalRead(VPB);
  SYNC_status = digitalRead(SYNC);
  address = ReadAddressLines();
  // do not read data here!
}

void WaitForClockHigh() {
  while (!clockState) {
    checkInternalClock();
  }
  RWB_status = digitalRead(RWB);
  VPB_status = digitalRead(VPB);
  SYNC_status = digitalRead(SYNC);
  address = ReadAddressLines();
  // do not read data here!
}

void WriteDataLines(uint8_t somedata) {
  DDRA = B11111111;  // set pins to output
  PORTA = somedata;
  data = somedata;
}

uint8_t ReadDataLines() {
  DDRA = B00000000;  //all input
  uint8_t byteread = PINA;
  data = byteread;
  return byteread;
}

uint16_t ReadAddressLines() {
  uint16_t addressread = PINB | (PINC << 8);
  return addressread;
}

void SetDataPinsToInput() {
  DDRA = B00000000;
}

void SetAddressPinsToInput() {
  DDRB = B00000000; 
  DDRC = B00000000;
}