#ifndef STATE_H
#define STATE_H

#include<vector>
#include "transition.h"

class State {
private:
    unsigned int id;
    std::vector<Transition *> transitions;
public:

    State(unsigned int id = 0);

    State(const State &other);

    ~State();

    bool operator==(const State &other);

    State &operator=(const State &other);

    void addTransition(Transition &transition);

    // If you pass a pointer we do not copy it and assume it is dynamic pointer we take care of its memory management
    void addTransition(Transition *transition);

    void addTransition(State &to, char label);

    void addTransition(State *to, char label);

    unsigned int getId() const {
        return id;
    }

    std::vector<Transition *> getTransitions();

};

#endif
