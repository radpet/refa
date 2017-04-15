#ifndef TRANSITION_H
#define TRANSITION_H

#include "state.h"

class State;

class Transition {
private:
    State *to;
    char label;
public:
    static const char EPSILON;

    Transition(State &to, char label);

    Transition(State *to, char label);

    State *getTo();

    char getLabel();

};

#endif
