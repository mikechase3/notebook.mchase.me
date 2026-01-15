//
//   __          __      __  __             
//   \ \        / /     |  \/  |            
//    \ \  /\  / /__ ___| \  / | ___  _ __  
//     \ \/  \/ / _ \_  / |\/| |/ _ \| '_ \ 
//      \  /\  / (_) / /| |  | | (_) | | | |
//       \/  \/ \___/___|_|  |_|\___/|_| |_| 
//
//     Do not use arduino environment... use a terminal program like PuTTy
//------------------------------------------------
// ADDR           = Examine memory at ADDR
// ADDR: XX ...   = Store hex bytes at ADDR
// ADDR1.ADDR2    = Dump memory from ADDR1–ADDR2
// ADDRR          = Run program at ADDR
// RETURN         = Next memory location
// RESET          = Return to monitor
//------------------------------------------------



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
const unsigned int SuperFastCounterResetValue = 0xFFFF;

const uint8_t Op_Code_NOP = 0xEA;
const uint8_t Op_Code_JMP = 0x4C;

const uint16_t ROM_SIZE = 0x1800; //6KB
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

  FillRom(ROM);

  ResetCPU();
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
      uint16_t romaddress = address & 0x7FFF;  //subtract 32k from address so we can use the array index 
      WriteDataLines(ROM[romaddress]);
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
    ///Serial.println((char)UART_Data_read);
    UART_Set_Receive_Register_Full();
  }

  //if (clockState && superFastCounter == 0) {
  //  DumpData();
  //}
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
  Serial.println("WOZMON!!!  The memory explorer OS by Steve Wozniak.");
  Serial.println("--------------------------------------------");
  Serial.println("ADDR           = Examine memory at ADDR");
  Serial.println("ADDR: XX ...   = Store hex bytes at ADDR");
  Serial.println("ADDR1.ADDR2    = Dump memory from ADDR1–ADDR2");
  Serial.println("ADDRR          = Run program at ADDR");
  Serial.println("RETURN         = Next memory location");
  Serial.println("RESET          = Return to monitor");
  Serial.println("-------------------------------------------");
  Serial.println("In your terminal, be sure to set `Implicit LF in every CR`.");
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
      if (newAnalogClockSpeed < 15) {
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
      if (analogClockSpeed < 15) { // MAX!
        clockDelayInMs = 0;
        superFastCounter = SuperFastCounterResetValue;  // 4095
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