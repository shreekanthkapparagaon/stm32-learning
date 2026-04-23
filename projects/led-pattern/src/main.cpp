#include <Arduino.h>

#define LED_PIN PA5

// ----------- FUNCTIONS -----------

void blink(uint16_t delay_ms) {
    digitalWrite(LED_PIN, HIGH);
    delay(delay_ms);
    digitalWrite(LED_PIN, LOW);
    delay(delay_ms);
}

void fade() {
    for (int i = 0; i <= 255; i++) {
        analogWrite(LED_PIN, i);
        delay(5);
    }
    for (int i = 255; i >= 0; i--) {
        analogWrite(LED_PIN, i);
        delay(5);
    }
}

// ----------- SETUP -----------

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

// ----------- LOOP -----------

void loop() {
    // Slow blink (3 times)
    for (int i = 0; i < 3; i++) {
        blink(500);
    }

    // Fast blink (5 times)
    for (int i = 0; i < 5; i++) {
        blink(100);
    }

    // Fade effect
    fade();
}