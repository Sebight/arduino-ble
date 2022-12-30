#include "BLETransactionCallbacks.h"
#include "Arduino.h"
#include "modules/parser/ParserModule.h"


BLETransactionCallbacks::BLETransactionCallbacks() = default;

void BLETransactionCallbacks::onWrite(BLECharacteristic *pCharacteristic) {
    std::string value = pCharacteristic->getValue();
    ParserModule::parse(value);
}