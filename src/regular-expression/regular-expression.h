#ifndef REG_EXPRESSION_H
#define REG_EXPRESSION_H


class RegularExpression {
private:
    char *expr;
    int len;

    void swap(const RegularExpression &other);

public:

    RegularExpression(char *str);

    RegularExpression(const RegularExpression &other);

    RegularExpression &operator=(RegularExpression &other);

    ~RegularExpression();

    char *getExpression() const {
        return expr;
    }

    int length() const {
        return len;
    }
};

#endif