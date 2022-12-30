#include "BLECallbacks.h"
#include "Arduino.h"

void BLECallbacks::onConnect(BLEServer *pServer) {
    _onConnect();
}

void BLECallbacks::onDisconnect(BLEServer *pServer) {
    _onDisconnect();
}

BLECallbacks::BLECallbacks(std::function<void()> onConnect, std::function<void()> onDisconnect) {
    this->_onConnect = onConnect;
    this->_onDisconnect = onDisconnect;
    if (onConnect != nullptr) {
        _onConnect = onConnect;
    } else {
        _onConnect = []() {
            Serial.println("Connected");
        };
    }
    
    if (onDisconnect != nullptr) {
        _onDisconnect = onDisconnect;
    } else {
        _onDisconnect = []() {
            Serial.println("Disconnected");
        };
    }
}
