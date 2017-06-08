#ifndef REFA_PARSER_H
#define REFA_PARSER_H

#include "regular-expression/regular-expression.h"
#include "parser/token/parsed-token.h"


class Parser {
private:
    RegularExpression *regex;
    int cursor;

    const char * getNext();

public:
    Parser(RegularExpression &regex);

    bool hasNext();

    // Creates new parsed token wrapper
    // You should take care to free the memory
    ParsedToken *lookNext();

    // Creates new parsed token wrapper
    // You should take care to free the memory
    ParsedToken *readNext();

    RegularExpression *getRegex() const {
        return regex;
    }

};


#endif
