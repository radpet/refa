#ifndef REFA_OPERATOR_H
#define REFA_OPERATOR_H


class Operator {
private:
    char value;
public:
    static const char STAR = '*';
    static const char UNION = '|';
    static const char LEFT_P = '(';
    static const char RIGHT_P = ')';

    static bool canBeOperator(char op);

    Operator(char op);

    char getValue() const;

};


#endif
