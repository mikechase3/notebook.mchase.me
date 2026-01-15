const uint8_t testPins[] = {
  2,3,4,5,6,7,8,9,10,11,12,13,
  22,23,24,25,26,27,28,29,30,31,
  32,33,34,35,36,37,38,39,40,41,
  42,43,44,45,46,47,48,49,50,51,
  52,53
};

const uint8_t NUM_PINS = sizeof(testPins) / sizeof(testPins[0]);

void setup() {
  Serial.begin(57600);
  while (!Serial) {}

  Serial.println(F("Arduino Mega Digital Pin Short Test (PULLUP + LOW)"));
  Serial.println(F("==================================================="));

  for (uint8_t i = 0; i < NUM_PINS; i++) {

    // Set all pins to INPUT_PULLUP
    for (uint8_t j = 0; j < NUM_PINS; j++) {
      pinMode(testPins[j], INPUT_PULLUP);
    }

    // Drive one pin LOW
    uint8_t drivenPin = testPins[i];
    pinMode(drivenPin, OUTPUT);
    digitalWrite(drivenPin, LOW);

    delay(5); // settle time

    Serial.print(F("Driving pin "));
    Serial.print(drivenPin);
    Serial.println(F(" LOW"));

    bool found = false;

    for (uint8_t j = 0; j < NUM_PINS; j++) {
      if (j == i) continue;

      uint8_t readPin = testPins[j];
      if (digitalRead(readPin) == LOW) {
        Serial.print(F("  -> Pin "));
        Serial.print(readPin);
        Serial.println(F(" reads LOW (possible short)"));
        found = true;
      }
    }

    if (!found) {
      Serial.println(F("  No shorts detected"));
    }

    Serial.println();
    delay(250);
  }

  Serial.println(F("Test complete.\n"));
}

void loop() {
  
}
