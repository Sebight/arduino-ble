#include <BLEDevice.h>
#include <BLE2902.h>
#include "BluetoothModule.h"
#include "Arduino.h"
#include "utils/Feedbacker.h"
#include "modules/helpers/BLECallbacks.h"
#include "modules/helpers/BLETransactionCallbacks.h"

BluetoothModule::BluetoothModule() = default;

void BluetoothModule::init() {
    _server = nullptr;
    _service = nullptr;
    _characteristic = nullptr;
    advertise();
    Feedbacker::led(2, 100);
    Serial.println("Bluetooth module initialized");
}

BluetoothModule::~BluetoothModule() {

}

void BluetoothModule::advertise() {
    _characteristic = nullptr;
    
    Serial.println("Advertising...");
    BLEUUID serviceUUID("4fafc201-1fb5-459e-8fcc-c5c9c331914b");
    BLEUUID charUUID("beb5483e-36e1-4688-b7f5-ea07361b26a8");
    Serial.println("UUIDs created");

    BLEDevice::init("ESP32");
    Serial.println("Device initialized");
    if (_server == nullptr)
    {
        _server = BLEDevice::createServer();
        Serial.println("Server created");
    } else {
        Serial.println("Server already created");
    }
    if (_service == nullptr)
    {
        _service = _server->createService(serviceUUID);
        Serial.println("Service created");
    } else {
        Serial.println("Service already created");
    }

    _characteristic = _service->createCharacteristic(
            charUUID,
            BLECharacteristic::PROPERTY_READ |
            BLECharacteristic::PROPERTY_WRITE
    );
    _characteristic->setValue("Hello World says Neil");
    _characteristic->addDescriptor(new BLE2902());
    _characteristic->setCallbacks(new BLETransactionCallbacks());
    Serial.println("Characteristic created");
    _service->start();
    Serial.println("Service started");
    _server->setCallbacks(new BLECallbacks([]() {
        Feedbacker::led(2, 100);
        Serial.println("Connected");
    }, [this]() {
        Feedbacker::led(2, 0);
        Serial.println("Disconnected");
        _server->getAdvertising()->stop();
        Serial.println("Restarting advertising");
        advertise();
    }));
    Serial.println("Callbacks set");
    _server->getAdvertising()->start();
    Serial.println("Advertising started");
}
