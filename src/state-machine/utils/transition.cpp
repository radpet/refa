#include "transition.h"

const char Transition::EPSILON = 'e';

Transition::~Transition() {
    delete to;
}

Transition::Transition(const Transition &other) {
    *this = other;
}

Transition &Transition::operator=(const Transition &other) {
    this->to = other.to->clone();
    this->label = other.getLabel();
}

Transition::Transition(State &to, char label) {
    this->to = to.clone();
    this->label = label;
}

Transition::Transition(State *to, char label) {
    this->to = to->clone();
    this->label = label;
}

const State *Transition::getTo() const {
    return to;
}

char Transition::getLabel() const {
    return label;
}

Transition *Transition::clone() const {
    return new Transition(*this);
}
