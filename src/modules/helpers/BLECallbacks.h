#ifndef UNTITLED_BLECALLBACKS_H
#define UNTITLED_BLECALLBACKS_H


#include "../../../../../../../.platformio/packages/framework-arduinoespressif32/libraries/BLE/src/BLEServer.h"
#include "../../../../../../../.platformio/packages/framework-arduinoespressif32/cores/esp32/Arduino.h"
#include "../../../../../../../.platformio/packages/toolchain-xtensa-esp32/xtensa-esp32-elf/include/c++/8.4.0/functional"

class BLECallbacks : public BLEServerCallbacks {
public:
    BLECallbacks(std::function<void()> onConnect = nullptr, std::function<void()> onDisconnect = nullptr);

    void onConnect(BLEServer *pServer) override;

    void onDisconnect(BLEServer *pServer) override;
    
private:
    std::function<void()> _onConnect;
    std::function<void()> _onDisconnect;
};


#endif //UNTITLED_BLECALLBACKS_H
