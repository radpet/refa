#include "argument.h"
#include<cstring>

Argument::Argument() : key(nullptr), value(nullptr) {}

Argument::Argument(const char *_key, const char *_value) {
    _copy(_key, _value);
}

void Argument::_copy(const char *_key, const char *_value) {
    if (_key != nullptr) {
        int len = strlen(_key);
        key = new char[len];
        strcpy(key, _key);
    }

    if (_value != nullptr) {
        int len = strlen(_value);
        _value = new char[len];
        strcpy(value, _value);
    }
}

Argument::Argument(const Argument &other) {
    *this = other;
}

Argument &Argument::operator=(const Argument &other) {
    _copy(other.value, other.key);
}

Argument::~Argument() {
    delete key;
    delete value;
}