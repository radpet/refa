
#include "arguments-parser.h"


ArgumentsParser::ArgumentsParser() : argCount(0), index(0), arguments(nullptr) {}

ArgumentsParser::ArgumentsParser(int argc, char **argv) : argCount(argc), index(0), arguments(argv) {}

bool ArgumentsParser::hasNext() {
    return index < argCount;
}

Argument *ArgumentsParser::next() {
    index++;
}