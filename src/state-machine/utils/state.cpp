#include "state.h"
#include <math.h>

State::State(unsigned int id, unsigned int automataId) {
    this->id = id;
    this->automataId = automataId;
}

State::State(unsigned int id, unsigned int automataId, std::vector<Transition *> &transitions) {
    this->id = id;
    this->automataId = automataId;

    for (Transition *transition:transitions) {
        this->transitions.push_back(new Transition(*transition));
    }
}

State::State(const State &other) {
    *this = other;
}

State::~State() {
    for (int i = 0; i < transitions.size(); i++) {
        delete transitions[i];
    }
    transitions.clear();
}

State &State::operator=(const State &other) {
    if (this != &other) {
        id = other.id;
        automataId = other.automataId;

        for (int i = 0; i < transitions.size(); i++) {
            delete transitions[i];
        }
        transitions.clear();

        for (Transition *transition:other.transitions) {
            transitions.push_back(new Transition(*transition));
        }
    }
    return *this;
}

bool State::operator==(const State &other) {
    return id == other.id && automataId == other.automataId;
}

void State::addTransition(Transition &other) {
    Transition *transition = new Transition(other);
    addTransition(transition);
}

void State::addTransition(Transition *transition) {
    transitions.push_back(new Transition(*transition));
}

void State::addTransition(State &to, char label) {
    Transition *transition = new Transition(&to, label);
    return addTransition(transition);
}

void State::addTransition(State *to, char label) {
    Transition *transition = new Transition(to, label);
    return addTransition(transition);
}

const std::vector<Transition *> State::getTransitions() const {
    return transitions;
}

void State::serialize(std::ostream &out) const {
    char *id1 = intToString(id);
    char *id2 = intToString(automataId);

    out << "{\n";
    out << "\"id1\":" << "\"" << id1 << "\"," << "\n";
    out << "\"id2\":" << "\"" << id2 << "\"," << "\n";
    out << "\"transitions\":[";

    for (int i = 0; i < transitions.size(); i++) {
        out << "{\n";
        out << "\"to\":";
        transitions[i]->getTo()->serialize(out);
        out << ",\n";
        out << "\"label\":" << "\"" << transitions[i]->getLabel() << "\"";
        out << "\n";
        out << "}";
        if (i != transitions.size() - 1) {
            out << ",\n";
        }
    }
    out << "]\n";
    out << "}";

    delete id1;
    delete id2;
}

char *State::intToString(int num) const {
    char *buffer = new char[16];
    int copy_of_num = num;
    int pos = 0;

    if (num == 0) {
        buffer[0] = '0';
        pos++;
    }

    int digits = 0;
    while (num != 0) {
        digits++;
        num /= 10;
    }

    num = copy_of_num;
    while (num != 0) {
        buffer[pos] = '0' + (num / pow(10, digits - 1));
        num %= (int) pow(10, digits - 1);
        digits--;
        pos++;
    }

    buffer[pos] = '\0';

    return buffer;
}