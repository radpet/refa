#include "transition.h"

const char Transition::EPSILON = 'e';

Transition::~Transition() {
    delete to;
}

Transition::Transition(const Transition &other) {
    this->to = new State(*other.to);
    this->label = other.getLabel();
}

Transition::Transition(State &to, char label) {
    this->to = new State(to);
    this->label = label;
}

Transition::Transition(State *to, char label) {
    this->to = new State(*to);
    this->label = label;
}

const State *Transition::getTo() const {
    return to;
}

char Transition::getLabel() const {
    return label;
}
