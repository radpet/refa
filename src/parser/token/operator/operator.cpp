#include "operator.h"

Operator::Operator(char op) {
    value = op;
    type = TokenType::Operator;
}

bool Operator::canBeOperator(char op) {
    return op == Operator::STAR ||
           op == Operator::UNION ||
           op == Operator::LEFT_P ||
           op == Operator::CONCAT ||
           op == Operator::RIGHT_P;
}