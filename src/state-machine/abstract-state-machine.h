//
// Abstract class that provides the common interface for both nfa and dfa state machines
//

#ifndef ABSTRACT_STATE_MACHINE_H
#define ABSTRACT_STATE_MACHINE_H

class AbstractStateMachine {
public:


    // Concatenate
    // may use * operator
    virtual AbstractStateMachine *concat(AbstractStateMachine &other) = 0;

    virtual AbstractStateMachine *kleene() = 0;

    virtual AbstractStateMachine *_union(AbstractStateMachine &other) = 0;
};


#endif
