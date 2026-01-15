const uint8_t testPins[] = {
  7,8,9,10,11,12,13,20,21,
  22,23,24,25,26,27,28,29,30,31,
  32,33,34,35,36,37,38,39,40,41,
  42,43,44,45,46,47,48,49,50,51,
  52,53
};

const uint8_t NUM_PINS = sizeof(testPins) / sizeof(testPins[0]);

// Track last-known state of each pin
uint8_t lastState[NUM_PINS];

void setup() {
  Serial.begin(57600);
  while (!Serial) {}

  Serial.println(F("Arduino Mega Ground Probe Test"));
  Serial.println(F("Touch GND to a pin to detect it"));
  Serial.println(F("================================"));

  // Configure pins and initialize state
  for (uint8_t i = 0; i < NUM_PINS; i++) {
    pinMode(testPins[i], INPUT_PULLUP);
    lastState[i] = digitalRead(testPins[i]);
  }
}

void loop() {
  for (uint8_t i = 0; i < NUM_PINS; i++) {
    uint8_t currentState = digitalRead(testPins[i]);

    // Detect HIGH -> LOW transition
    if (lastState[i] == HIGH && currentState == LOW) {
      Serial.print(F("Pin "));
      Serial.print(testPins[i]);
      Serial.println(F(" went LOW"));
    }

    // Update stored state
    lastState[i] = currentState;
  }

  delay(100); // small delay to reduce noise / CPU usage
}
