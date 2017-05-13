#include "parser.h"

#include "parser/token/operator/operator.h"
#include "parser/token/letter/letter.h"

Parser::Parser(RegularExpression &regex) {
    this->regex = &regex;
    cursor = 0;
}

bool Parser::hasNext() {
    return cursor < regex->length();
}

char *Parser::getNext() {
    if (hasNext()) {
        return regex->getExpression() + cursor;
    }

    return nullptr;
}

ParsedToken *Parser::lookNext() {
    if (hasNext()) {
        char *nextChar = getNext();
        if (Operator::canBeOperator(*nextChar)) {
            return new ParsedToken(new Operator(*nextChar));
        } else {
            return new ParsedToken(new Letter(*nextChar));
        }
    }

    return nullptr;
}

ParsedToken *Parser::readNext() {
    if (hasNext()) {
        char *nextChar = getNext();
        cursor += 1;
        if (Operator::canBeOperator(*nextChar)) {
            return new ParsedToken(new Operator(*nextChar));
        } else {
            return new ParsedToken(new Letter(*nextChar));
        }
    }

    return nullptr;
}

