#ifndef REG_EXPRESSION_H
#define REG_EXPRESSION_H


class RegularExpression {
private:
    char *expr;
    int len;

public:

    RegularExpression(char *str);

    ~RegularExpression();

    char *getExpression() const {
        return expr;
    }

    int length() const {
        return len;
    }
};

#endif