#ifndef NFA_H
#define NFA_H

#include "../abstract-state-machine.h"
#include "../utils/state.h"

class NFA : public AbstractStateMachine {
private:
    std::vector<State> states;
    State *startState;
    State *finalState;

    void swap(const NFA &other);

public:
    NFA();

    ~NFA();

    NFA(const NFA &other);

    NFA(State &startState, State &finalState);

    NFA &operator=(const NFA &other);

    NFA *concat(AbstractStateMachine &other);

    NFA *kleene();

    NFA *_union(AbstractStateMachine &other);

    std::vector<State> &getStates() {
        return states;
    }


    State *getStartState() {
        return startState;
    }

    State *getFinalState() {
        return finalState;
    }

    void setStartState(State *startState);

    void setFinalState(State *finalState);

};


#endif
