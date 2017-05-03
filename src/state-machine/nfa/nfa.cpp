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

NFA *NFA::concat(NFA &other) {

    for (int i = 0; i < other.getStates().size(); i++) {
        State *state = new State(*other.getStates()[i]);
        states.push_back(state);
    }
    Transition transition = Transition(other.getStartState(), Transition::EPSILON);
    finalState->addTransition(other.getStartState(), Transition::EPSILON);
    setFinalState(*other.getFinalState());

    return this;

}

NFA *NFA::kleene() {}

NFA *NFA::_union(NFA &other) {}


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

void NFA::updateStartOrFinalState(State **startOrFinal, State &state) { //cool double pointers why?

    if (hasState(state)) {
        *startOrFinal = findState(state);
    } else {
        *startOrFinal = new State(state);
        states.push_back(&(**startOrFinal));
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
