#include "state.h"

State::State(unsigned int id) {
    this->id = id;
}

int State::getId() {
    return id;
}

bool State::operator==(const State &other) {
    return id == other.id;
}