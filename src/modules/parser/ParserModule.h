#ifndef UNTITLED_PARSERMODULE_H
#define UNTITLED_PARSERMODULE_H


#include <string>
#include "modules/base/IModule.h"

class ParserModule : public IModule {
public:
    ParserModule();

    void init() override;
    static void parse(std::string data);
};


#endif //UNTITLED_PARSERMODULE_H
