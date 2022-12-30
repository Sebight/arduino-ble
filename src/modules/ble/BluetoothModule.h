#ifndef UNTITLED_BLUETOOTHMODULE_H
#define UNTITLED_BLUETOOTHMODULE_H

#include "modules/base/IModule.h"
#include <BLEDevice.h>
#include <BLEServer.h>

class BluetoothModule : public IModule {
public:
    BluetoothModule();
    ~BluetoothModule();
    
    void init() override;
    void advertise();
    
private: 
    BLEServer* _server;
    BLEService* _service;
    BLECharacteristic* _characteristic;
};


#endif //UNTITLED_BLUETOOTHMODULE_H
