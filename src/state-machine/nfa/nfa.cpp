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
    for (State *state : states) {
        delete state;
    }
    states.clear();
}

void NFA::swap(const NFA &other) {
    startState = new State(*other.startState);
    finalState = new State(*other.finalState);
    states = other.states;
}

NFA &NFA::operator=(const NFA &other) {
    swap(other);
    return *this;
}

NFA *NFA::concat(AbstractStateMachine &other) {
    NFA &toConcat = dynamic_cast<NFA &>(other);
    if (&toConcat) {
        for (int i = 0; i < toConcat.getStates().size(); i++) {
            State *state = new State(*toConcat.getStates()[i]);
            states.push_back(state);
        }
        Transition transition = Transition(toConcat.getStartState(), Transition::EPSILON);
        finalState->addTransition(toConcat.getStartState(), Transition::EPSILON);
        setFinalState(*toConcat.getFinalState());
    }
    return this;

}

NFA *NFA::kleene() {}

NFA *NFA::_union(AbstractStateMachine &other) {}


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
