#include "Feedbacker.h"
#include "Arduino.h"

Feedbacker::Feedbacker() = default;

void Feedbacker::led(int pin, int _delay) {
    digitalWrite(pin, HIGH);
    delay(_delay);
    digitalWrite(pin, LOW);
}
