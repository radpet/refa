#include "state.h"

State::State(unsigned int id, unsigned int automataId) {
    this->id = id;
    this->automataId = automataId;
}

State::State(unsigned int id, unsigned int automataId, std::vector<Transition *> &transitions) {
    this->id = id;
    this->automataId = automataId;

    for (Transition *transition:transitions) {
        this->transitions.push_back(new Transition(*transition));
    }
}

State::State(const State &other) {
    *this = other;
}

State::~State() {
    for (int i = 0; i < transitions.size(); i++) {
        delete transitions[i];
    }
    transitions.clear();
}

State &State::operator=(const State &other) {
    id = other.id;
    automataId = other.automataId;
    for (Transition *transition:other.transitions) {
        transitions.push_back(new Transition(*transition));
    }
    return *this;
}

bool State::operator==(const State &other) {
    return id == other.id && automataId == other.automataId;
}

void State::addTransition(Transition &other) {
    Transition *transition = new Transition(other);
    addTransition(transition);
}

void State::addTransition(Transition *transition) {
    transitions.push_back(new Transition(*transition));
}

void State::addTransition(State &to, char label) {
    Transition *transition = new Transition(&to, label);
    return addTransition(transition);
}

void State::addTransition(State *to, char label) {
    Transition *transition = new Transition(to, label);
    return addTransition(transition);
}

std::vector<Transition *> State::getTransitions() {
    return transitions;
}