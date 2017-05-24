#include<cstring>
#include "./regular-expression.h"

RegularExpression::RegularExpression(const char *str) {
    len = std::strlen(str);
    expr = new char[len];
    std::strcpy(expr, str);
}

RegularExpression::RegularExpression(const RegularExpression &other) {
    swap(other);
}

RegularExpression &RegularExpression::operator=(RegularExpression &other) {
    swap(other);
    return *this;
}

void RegularExpression::swap(const RegularExpression &other) {
    if (this != &other) {
        len = other.length();
        delete[] expr;
        expr = new char[len];
        std::strcpy(expr, other.getExpression());
    }
}

RegularExpression::~RegularExpression() {
    delete[] expr;
}