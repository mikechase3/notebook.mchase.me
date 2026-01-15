
const char CLOCK=41;
const char CLOCKLED=4;


bool clockState = false;  //false==clock low    true==clock high.


// use internal clock, (a potentiometer connected to analog input 7, and a N-O button connected to digital input 7)
const char analogClockSpeedPin = A7;  // center pin of potentiometer
const char stepClockButtonPin = 6;   // button that steps the clock

int analogClockSpeed = 0;
unsigned long clockDelayInMs = 0;
unsigned long clockFlopStart = 0;
unsigned int superFastCounter = 0;
const unsigned int SuperFastCounterResetValue = 0xFFF;
const unsigned int SuperFastThreshold = 0x0014;

void setup() {

  //initialize internal clock
  pinMode(CLOCK, OUTPUT);
  pinMode(CLOCKLED, OUTPUT);
  digitalWrite(CLOCK, LOW);
  digitalWrite(CLOCKLED, LOW);
  pinMode(stepClockButtonPin, INPUT);
  clockFlopStart = millis();

  Serial.begin(57600);
  Serial.println("Clock started.");

}

void loop() {
  checkInternalClock();
}


void DumpData() {
  Serial.print(" potentiometer input:  ");
  Serial.print(analogClockSpeed);
  Serial.print("   CLOCK:");
  Serial.println(clockState);
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
        Serial.println("Continuing super fast mode....");
      }
    }
    return;
  }

  unsigned long timediff = (millis() - clockFlopStart);
  int newAnalogClockSpeed = analogRead(analogClockSpeedPin);
  if (newAnalogClockSpeed > 1000) {  //clock is off... 
    if (analogClockSpeed < 1000) {  // we have just transitioned from Clock-ON to Clock-OFF.
      Serial.println("Clock is stopped. Use button to manually step the clock.");
      digitalWrite(CLOCKLED, 0);
      delay(100);
    }
    char hilow = digitalRead(stepClockButtonPin);
    analogClockSpeed = newAnalogClockSpeed;
    if (timediff > 50 && hilow != clockState) {  // we are making sure 90ms has passed because we have to de-bounce the input.
      flopTheClock();
      digitalWrite(CLOCKLED, clockState);
      DumpData();
    }
  }
  else {
    if (abs(newAnalogClockSpeed - analogClockSpeed) > 5) { //it has changed!
      if (analogClockSpeed > 1000) {
        Serial.println("Clock is running. Use button to stop the clock.");
      }
      analogClockSpeed = newAnalogClockSpeed;
      if (analogClockSpeed < SuperFastThreshold) {
        clockDelayInMs = 0;
        superFastCounter = SuperFastCounterResetValue;
        Serial.println("");
        Serial.println("entering super fast mode....");
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
        DumpData();
      }
    }
  }
}
void flopTheClock() {
  clockState = !clockState;
  digitalWrite(CLOCK, clockState);
  clockFlopStart = millis();
}
