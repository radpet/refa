#ifndef STATE_H
#define STATE_H

#include<vector>
#include "writer/serializable.h"
#include "transition.h"
#include "utils/cloneable.h"

class Transition;

class State : public Serializable, public Cloneable<State> {
private:
    // fist index internal for automata
    unsigned int id;
    // second index to distinguish states
    unsigned int automataId;
    std::vector<Transition *> transitions;

    char *intToString(int num) const;

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

    virtual void serialize(std::ostream &out) const;

    virtual State *clone() const;

};

#endif
