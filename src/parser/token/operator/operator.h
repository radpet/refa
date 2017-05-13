#ifndef REFA_OPERATOR_H
#define REFA_OPERATOR_H

#include "parser/token/token.h"

class Operator : public Token {
public:
    static const char STAR = '*';
    static const char UNION = '|';
    static const char CONCAT = '.';
    static const char LEFT_P = '(';
    static const char RIGHT_P = ')';

    static bool canBeOperator(char op);

    Operator(char op);

};


#endif
