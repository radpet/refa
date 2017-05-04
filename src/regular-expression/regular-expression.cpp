#include<cstring>
#include "./regular-expression.h"

RegularExpression::RegularExpression(char *str) {
    len = std::strlen(str);
    expr = new char[len];
    std::strcpy(expr, str);
}

RegularExpression::~RegularExpression() {
    delete[] expr;
}