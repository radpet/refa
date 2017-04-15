#ifndef STATE_H
#define STATE_H

#include<vector>
#include "transition.h"

// @TODO I can remove this once I use references in the vector
class Transition;

class State {
private:
    unsigned int id;
    std::vector<Transition> transitions;
public:

    State(unsigned int id = 0);

    State(const State &other);


    bool operator==(const State &other);

    bool addTransition(Transition &transition);

    bool addTransition(State &to, char label);

    bool addTransition(State *to, char label);

    unsigned int getId() const {
        return id;
    }

    std::vector<Transition> getTransitions();

};

#endif
