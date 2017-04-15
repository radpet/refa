#include "state.h"

State::State(unsigned int id) {
    this->id = id;
}

State::State(const State &other) {
    id = other.id;
    transitions = other.transitions;
}

bool State::operator==(const State &other) {
    return id == other.id;
}

bool State::addTransition(Transition &transition) {
    transitions.push_back(transition);
}

bool State::addTransition(State &to, char label) {
    Transition transition = Transition(&to, label);
    addTransition(transition);
}

bool State::addTransition(State *to, char label) {
    Transition transition = Transition(to, label);
    addTransition(transition);
}

std::vector<Transition> State::getTransitions() {
    return transitions;
}