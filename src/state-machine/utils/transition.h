#ifndef TRANSITION_H
#define TRANSITION_H

#include "state.h"

// @TODO why should I use forward declaration here?
class State;

class Transition {
private:
    State *to;
    char label;
public:
    static const char EPSILON;

    Transition(Transition *other);

    Transition(const Transition &other);

    Transition(State &to, char label);

    Transition(State *to, char label);

    State *getTo() const;

    char getLabel() const;

};

#endif
