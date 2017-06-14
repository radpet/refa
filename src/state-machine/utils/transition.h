#ifndef TRANSITION_H
#define TRANSITION_H

#include "state.h"
#include "utils/cloneable.h"

// @TODO why should I use forward declaration here?
class State;

class Transition : public Cloneable<Transition> {
private:
    State *to;
    char label;
public:
    static const char EPSILON;

    ~Transition();

    // Deep copy the label and state it points to
    Transition(Transition *other);

    // Deep copy the transition object passed as param
    Transition(const Transition &other);

    // Deep copy the state
    Transition(State &to, char label);

    // Deep copy the state the pointer points
    Transition(State *to, char label);

    Transition &operator=(const Transition &other);

    const State *getTo() const;

    char getLabel() const;

    virtual Transition *clone() const;

};

#endif
