#ifndef REFA_OPERATOR_H
#define REFA_OPERATOR_H

#include "parser/token/token.h"

class Operator : public Token {
private :
    int priority;
public:
    static const char STAR = '*';
    static const int STAR_PRIORITY = 3;

    static const char CONCAT = '.';
    static const int CONCAT_PRIORITY = 2;

    static const char UNION = '|';
    static const int UNION_PRIORITY = 1;

    static const char LEFT_P = '(';
    static const char RIGHT_P = ')';

    static bool canBeOperator(char op);

    static int findPriority(char op);

    Operator(char op, int priority = 0);

    int getPriority() const {
        return priority;
    }

};


#endif
