
#ifndef REFA_ARGUMENTSPARSER_H
#define REFA_ARGUMENTSPARSER_H

#include "argument.h"

class ArgumentsParser {
private:
    int argCount;
    int index;
    char *arguments[];
public:
    ArgumentsParser();

    ArgumentsParser(int argc, char *argv[]);

    bool hasNext();

    Argument *next();

};


#endif //REFA_ARGUMENTSPARSER_H
