#ifndef REFA_TOKEN_H
#define REFA_TOKEN_H

#include "token-type.h"

class Token {
protected:
    char value;
    TokenType type;
public:
    virtual char getValue() const {
        return value;
    }

    virtual TokenType getType() const {
        return type;
    }
};


#endif
