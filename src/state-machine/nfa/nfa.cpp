#include "nfa.h"

NFA::NFA() {
    startState = nullptr;
    finalState = nullptr;
}

NFA::NFA(const NFA &other) {
    *this = other;
}

NFA::NFA(State &startState, State &finalState) {
    this->startState = new State(startState);
    this->finalState = new State(finalState);

    if (startState == finalState) {
        states.push_back(*(this->startState));
    } else {
        states.push_back(*(this->startState));
        states.push_back(*(this->finalState));
    }

}

NFA::~NFA() {
    delete finalState;
}

void NFA::swap(const NFA &other) {
    *finalState = *other.finalState;
    states = other.states;
}

NFA &NFA::operator=(const NFA &other) {
    swap(other);
    return *this;
}

NFA *NFA::concat(AbstractStateMachine &other) {
    NFA &toConcat = dynamic_cast<NFA &>(other);
    if (&toConcat) {
        for (auto state : toConcat.getStates()) {
            states.push_back(state);
        }
        Transition transition = Transition(toConcat.getStartState(), Transition::EPSILON);
        finalState->addTransition(transition);
        setFinalState(toConcat.getFinalState());
    }
    return this;

}

NFA *NFA::kleene() {}

NFA *NFA::_union(AbstractStateMachine &other) {}

void NFA::setStartState(State *startState) {
    *(this->startState) = *startState;
}

void NFA::setFinalState(State *finalState) {
    *(this->finalState) = *finalState;
}
