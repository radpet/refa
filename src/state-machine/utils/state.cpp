#include "state.h"

State::State(unsigned int id) {
    this->id = id;
}

// Deep copy the state
State::State(const State &other) {
    id = other.id;
    for (int i = 0; i < other.transitions.size(); i++) {
        transitions.push_back(new Transition(*other.transitions[i]));
    }
}

State::~State() {
    for (int i = 0; i < transitions.size(); i++) {
        delete transitions[i];
    }
    transitions.clear();
}

State &State::operator=(const State &other) {
    id = other.id;
    for (Transition *transition:other.transitions) {
        transitions.push_back(new Transition(*transition));
    }
}

bool State::operator==(const State &other) {
    return id == other.id;
}

void State::addTransition(Transition &other) {
    Transition *transition = new Transition(other);
    addTransition(transition);
}

void State::addTransition(Transition *transition) {
    transitions.push_back(new Transition(*transition));
};

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