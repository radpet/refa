#include "letter.h"

Letter::Letter(char ch) {
    value = ch;
    type = TokenType::Letter;
}