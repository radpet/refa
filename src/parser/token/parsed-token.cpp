#include "parsed-token.h"

ParsedToken::ParsedToken(Token *token) {
    this->token = token;
}

ParsedToken::~ParsedToken() {
    delete this->token;
}

bool ParsedToken::isOperator() {
    return token->getType() == TokenType::Operator;
}

bool ParsedToken::isLetter() {
    return token->getType() == TokenType::Letter;
}

char ParsedToken::get() {
    return token->getValue();
}