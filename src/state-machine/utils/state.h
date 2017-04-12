#ifndef STATE_H
#define STATE_H

class State {
private:
    unsigned int id;
public:

    State(unsigned int id = 0);

    int getId();

    bool operator==(const State &other);
};

#endif STATE_H
