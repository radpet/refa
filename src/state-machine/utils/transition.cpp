#include "transition.h"

Transition::Transition(State &from, State &to, char label) {
    this->from = &from;
    this->to = &to;
    this->label = label;
}

State &Transition::getFrom() {
    return *from;
}

State &Transition::getTo() {
    return *to;
}

char Transition::getLabel() {
    return label;
}