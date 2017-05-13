#ifndef REFA_COMPILER_H
#define REFA_COMPILER_H

#include "state-machine/nfa/nfa.h"
#include "regular-expression/regular-expression.h"
#include "parser/token/operator/operator.h"
#include <stack>

class RegularExpressionCompiler {
private:
    void preprocessForConcat(RegularExpression &expression);
    void processOperator(std::stack<Operator> &operators, std::stack<NFA> &constructedNFA);

public:
    RegularExpressionCompiler();

    NFA compile(RegularExpression expression);

};


#endif