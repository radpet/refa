#ifndef STATE_H
#define STATE_H

#include<vector>
#include "transition.h"

class Transition;

class State {
private:
    // fist index internal for automata
    unsigned int id;
    // second index to distinguish states
    unsigned int automataId;
    std::vector<Transition *> transitions;
public:

    State(unsigned int id = 0, unsigned int automataId = 0);

    // Deep copy the transitions
    State(unsigned int id, unsigned int automataId, std::vector<Transition *> &transitions);

    // Deep copy the id and transitions from other state
    State(const State &other);

    ~State();

    bool operator==(const State &other);

    State &operator=(const State &other);

    void addTransition(Transition &transition);

    void addTransition(Transition *transition);

    void addTransition(State &to, char label);

    void addTransition(State *to, char label);

    unsigned int getId() const {
        return id;
    }

    unsigned int getSecondId() const {
        return automataId;
    };

    const std::vector<Transition *> getTransitions() const;

};

#endif
