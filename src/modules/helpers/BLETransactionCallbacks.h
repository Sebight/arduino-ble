#ifndef UNTITLED_BLETRANSACTIONCALLBACKS_H
#define UNTITLED_BLETRANSACTIONCALLBACKS_H

#include "../../../../../../../.platformio/packages/framework-arduinoespressif32/libraries/BLE/src/BLECharacteristic.h"

class BLETransactionCallbacks: public BLECharacteristicCallbacks {
public:
    BLETransactionCallbacks();
    void onWrite(BLECharacteristic *pCharacteristic) override;
};


#endif //UNTITLED_BLETRANSACTIONCALLBACKS_H
