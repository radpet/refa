#ifndef NFA_H
#define NFA_H

#include "../utils/state.h"
#include "writer/serializable.h"

class NFA : public Serializable {
private:
    unsigned int automataId;
    std::vector<State *> states;
    State *startState = nullptr;
    State *finalState = nullptr;

    void swap(const NFA &other);

    unsigned int generateNewAutomataId(unsigned int oldId, unsigned int otherId);

    void updateStartOrFinalState(State **startOrFinal, State &state);

public:
    NFA();

    ~NFA();

    NFA(const NFA &other);

    NFA(State &startState, State &finalState, unsigned int automataId = 0);

    NFA &operator=(const NFA &other);

    NFA *concat(NFA &other);

    NFA *kleene();

    NFA *_union(NFA &other);

    bool hasState(State &state);

    State *findState(State &state);

    State *findState(State *state);

    void setStartState(State &startState);

    void setFinalState(State &finalState);

    std::vector<State *> &getStates() {
        return states;
    }

    void setAutomataId(unsigned int automataId) {
        this->automataId = automataId;
    }

    unsigned int getAutomataId() const {
        return automataId;
    }

    const State *getStartState();

    const State *getFinalState();

    virtual void serialize(std::ostream &out) const;


};


#endif
