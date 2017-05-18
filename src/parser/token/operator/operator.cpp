#include "operator.h"

Operator::Operator(char op, int priority) {
    value = op;
    type = TokenType::Operator;
    this->priority = priority;
}

bool Operator::canBeOperator(char op) {
    return op == Operator::STAR ||
           op == Operator::UNION ||
           op == Operator::LEFT_P ||
           op == Operator::CONCAT ||
           op == Operator::RIGHT_P;
}

int Operator::findPriority(char op) {
    if (op == Operator::STAR) return STAR_PRIORITY;
    if (op == Operator::UNION) return UNION_PRIORITY;
    if (op == Operator::CONCAT) return CONCAT_PRIORITY;

    return 0;
}