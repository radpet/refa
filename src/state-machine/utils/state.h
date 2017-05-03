#ifndef STATE_H
#define STATE_H

#include<vector>
#include "transition.h"

class Transition;

class State {
private:
    unsigned int id;
    std::vector<Transition *> transitions;
public:

    State(unsigned int id = 0);

    // Deep copy the transitions
    State(unsigned int id, std::vector<Transition *> &transitions);

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

    std::vector<Transition *> getTransitions();

};

#endif
