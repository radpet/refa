
#ifndef REFA_ARGUMENTSPARSER_H
#define REFA_ARGUMENTSPARSER_H

#include "argument.h"

class ArgumentsParser {
public:
    ArgumentsParser(int argc, char *argv[]);

    Argument *next();

};


#endif //REFA_ARGUMENTSPARSER_H
