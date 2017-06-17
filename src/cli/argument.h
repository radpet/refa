
#ifndef REFA_ARGUMENT_H
#define REFA_ARGUMENT_H


class Argument {
private:
    char *key;
    char *value;

    void _copy(const char *_key, const char *_value);

public:
    Argument();

    Argument(const char *_key, const char *_value);

    Argument(const Argument &other);

    Argument &operator=(const Argument &other);

    ~Argument();

    const char *getValue() const {
        return value;
    }

    const char *getKey() const {
        return key;
    }
};


#endif //REFA_ARGUMENT_H
