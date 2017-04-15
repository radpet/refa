#include "transition.h"

const char Transition::EPSILON = 'e';

Transition::Transition(State &to, char label) {
    this->to = &to;
    this->label = label;
}

Transition::Transition(State *to, char label) {
    this->to = to;
    this->label = label;
}


State *Transition::getTo() {
    return to;
}

char Transition::getLabel() {
    return label;
}
