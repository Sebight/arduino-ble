#include "ParserModule.h"
#include "Arduino.h"
#include "utils/Feedbacker.h"

void ParserModule::init() {
    Feedbacker::led(2, 100);
    Serial.println("ParserModule initialized");
}

void ParserModule::parse(std::string data) {
    Serial.println(data.c_str());
}

ParserModule::ParserModule() = default;
