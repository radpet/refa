#ifndef NFA_H
#define NFA_H

#include "../abstract-state-machine.h"
#include "../utils/state.h"

class NFA : public AbstractStateMachine {
private:
    std::vector<State*> states;
    State *startState = nullptr;
    State *finalState = nullptr;

    void swap(const NFA &other);

    void updateStartOrFinalState(State **startOrFinal, State &state);

public:
    NFA();

    ~NFA();

    NFA(const NFA &other);

    NFA(State &startState, State &finalState);

    NFA &operator=(const NFA &other);

    NFA *concat(AbstractStateMachine &other);

    NFA *kleene();

    NFA *_union(AbstractStateMachine &other);

    bool hasState(State &state);

    State *findState(State &state);

    void setStartState(State &startState);

    void setFinalState(State &finalState);

    std::vector<State*> &getStates() {
        return states;
    }

    State *getStartState();

    State *getFinalState();


};


#endif
