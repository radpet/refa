#include "operator.h"

Operator::Operator(char op) {
    value = op;
}

char Operator::getValue() const {
    return value;
}

bool Operator::canBeOperator(char op) {
    return op == Operator::STAR ||
           op == Operator::UNION ||
           op == Operator::LEFT_P ||
           op == Operator::RIGHT_P;
}