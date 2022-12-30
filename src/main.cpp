#include <Arduino.h>
#include <vector>
#include "modules/ble/BluetoothModule.h"
#include "modules/parser/ParserModule.h"
#include "utils/Feedbacker.h"

void setup() {
    Serial.begin(115200);
    pinMode(2, OUTPUT);
    delay(2000);
    Serial.println("ESP core initialized");
    Feedbacker::led(2, 100);

    std::vector<IModule*> modules{new BluetoothModule, new ParserModule};
    for (auto module : modules) {
        module->init();
    }
}

void loop() {
}