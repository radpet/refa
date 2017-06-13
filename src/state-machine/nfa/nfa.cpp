#include "nfa.h"

unsigned int max(int a, int b) {
    return a < b ? b : a;
}

NFA::NFA() {

}

NFA::NFA(const NFA &other) {
    *this = other;
}

NFA::NFA(State &startState, State &finalState, unsigned int automataId) {
    this->automataId = automataId;
    setStartState(startState);
    setFinalState(finalState);
}

NFA::~NFA() {
    while (!states.empty()) {
        State *state = states.back();
        states.pop_back();
        delete state;
    }
    states.clear();
}

void NFA::swap(const NFA &other) {
    if (this != &other) {
        delete startState;
        delete finalState;
        while (!states.empty()) {
            State *state = states.back();
            states.pop_back();
            delete state;
        }
        states.clear();

        startState = new State(*other.startState);
        finalState = new State(*other.finalState);
        automataId = other.automataId;
        for (int i = 0; i < other.states.size(); i++) {
            states.push_back(new State(*other.states[i]));
        }
    }
}

NFA &NFA::operator=(const NFA &other) {
    swap(other);
    return *this;
}

// Add all states to the current nfa
// Add epsilon transition from the current final to the other start and change the current final state
NFA *NFA::concat(NFA &other) {
    int newAutomataId = generateNewAutomataId(automataId, other.getAutomataId());
    for (int i = 0; i < other.getStates().size(); i++) {
        states.push_back(new State(*other.getStates()[i]));
    }
    //Transition transition = Transition(other.startState, Transition::EPSILON);

    //finalState->addTransition(other.startState, Transition::EPSILON);

    findState(*finalState)->addTransition(other.startState,Transition::EPSILON);

    //finalState = findState(*other.finalState);

    setFinalState(*other.finalState);

    automataId = newAutomataId;

    return this;
}

NFA *NFA::kleene() {

    State newStart = State(states.size() + 1, automataId);
    State newFinal = State(states.size() + 2, automataId);

    newStart.addTransition(newFinal, Transition::EPSILON);
    newStart.addTransition(startState, Transition::EPSILON);

    findState(*finalState)->addTransition(newFinal, Transition::EPSILON);
    findState(*finalState)->addTransition(startState, Transition::EPSILON);

    setStartState(newStart);
    setFinalState(newFinal);

    return this;
}

NFA *NFA::_union(NFA &other) {

    for (int i = 0; i < other.getStates().size(); i++) {
        states.push_back(new State(*other.getStates()[i]));
    }

    int newAutomataId = generateNewAutomataId(automataId, other.getAutomataId());
    State newStart = State(1, newAutomataId);
    State newFinal = State(2, newAutomataId);

    newStart.addTransition(startState, Transition::EPSILON);
    newStart.addTransition(findState(*other.startState), Transition::EPSILON);

    findState(*finalState)->addTransition(newFinal, Transition::EPSILON);
    findState(*other.finalState)->addTransition(newFinal, Transition::EPSILON);

    setStartState(newStart);
    setFinalState(newFinal);

    automataId = newAutomataId;

    return this;
}

unsigned int NFA::generateNewAutomataId(unsigned int oldId, unsigned int otherId) {
    return max(oldId, otherId) + 1;
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
    updateStartOrFinalState(&(this->startState), startState);
}

void NFA::setFinalState(State &finalState) {
    updateStartOrFinalState(&(this->finalState), finalState);
}

const State *NFA::getStartState() {
    return startState;
}

const State *NFA::getFinalState() {
    return finalState;
}

void NFA::serialize(std::ostream &out) const {

    // call serialize on each state

    out << "{\n";
    out << "\"nfa\":[";
    for (int i = 0; i < states.size(); i++) {
        states[i]->serialize(out);
        if (i != states.size() - 1) {
            out << ",\n";
        }
    }
    out << "],\n";
    out << "\"startState\":";
    startState->serialize(out);
    out << ",\n";
    out << "\"finalState\":";
    finalState->serialize(out);
    out << "}\n";
}
