#ifndef REFA_COMPILER_H
#define REFA_COMPILER_H

#include "state-machine/nfa/nfa.h"
#include "regular-expression/regular-expression.h"

class RegularExpressionCompiler {

public:
    RegularExpressionCompiler();

    NFA compile(RegularExpression expression);

};


#endif