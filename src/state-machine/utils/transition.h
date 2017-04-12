#ifndef TRANSITION_H
#define TRANSITION_H

#include "state.h"

class Transition {
private:
    State *from;
    State *to;
    char label;
public:
    Transition(State &from, State &to, char label);

    State &getFrom();

    State &getTo();

    char getLabel();

};

#endif TRANSITION_H
