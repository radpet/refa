#ifndef REFA_PARSED_TOKEN_H
#define REFA_PARSED_TOKEN_H


#include "token.h"

class ParsedToken {
private:
    Token *token;
public:
    ParsedToken(Token *token);

    ~ParsedToken();

    bool isOperator();

    bool isLetter();

};


#endif
