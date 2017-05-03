#include "nfa.h"

NFA::NFA() {

}

NFA::NFA(const NFA &other) {
    *this = other;
}

NFA::NFA(State &startState, State &finalState) {
    setStartState(startState);
    setFinalState(finalState);
}

NFA::~NFA() {
    while (!states.empty()) {
        delete states.back();
        states.pop_back();
    }
    states.clear();
}

void NFA::swap(const NFA &other) {
    startState = other.startState;
    finalState = other.finalState;
    for (int i = 0; i < other.states.size(); i++) {
        states.push_back(other.states[i]);
    }
}

NFA &NFA::operator=(const NFA &other) {
    swap(other);
    return *this;
}

// Add all states to the current nfa
// Add epsilon transition from the current final to the other start and change the current final state
NFA *NFA::concat(NFA &other) {

    for (int i = 0; i < other.getStates().size(); i++) {
        State *state = new State(*other.getStates()[i]);
        states.push_back(state);
    }
    Transition transition = Transition(other.getStartState(), Transition::EPSILON);
    finalState->addTransition(transition);
    setFinalState(*other.getFinalState());

    return this;

}

NFA *NFA::kleene() {

    State newStart = State(states.size() + 1);
    State newFinal = State(states.size() + 2);

    newStart.addTransition(newFinal, Transition::EPSILON);
    newStart.addTransition(startState, Transition::EPSILON);

    finalState->addTransition(newFinal, Transition::EPSILON);
    finalState->addTransition(startState, Transition::EPSILON);

    setStartState(newStart);
    setFinalState(newFinal);

    return this;
}

NFA *NFA::_union(NFA &other) {

}


bool NFA::hasState(State &state) {
    if (findState(state) == nullptr) {
        return false;
    }
    return true;
}

State *NFA::findState(State &state) {
    for (int i = 0; i < states.size(); i++) {
        if (*states[i] == state) {
            return states[i];
        }
    }
    return nullptr;
}

// First check if we have the state in the current states by looking at its id
// If it is not found deep copy the state and add it to the states;
void NFA::updateStartOrFinalState(State **startOrFinal, State &state) {

    if (hasState(state)) {
        *startOrFinal = findState(state);
    } else {
        *startOrFinal = new State(state);
        states.push_back(*startOrFinal);
    }
}

void NFA::setStartState(State &startState) {
    updateStartOrFinalState(&this->startState, startState);
}

void NFA::setFinalState(State &finalState) {
    updateStartOrFinalState(&this->finalState, finalState);
}

State *NFA::getStartState() {
    return startState;
}

State *NFA::getFinalState() {
    return finalState;
}
