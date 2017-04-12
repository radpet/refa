#include "gtest/gtest.h"
#include "../src/state-machine/utils/state.h"

TEST(StateTest, ItShouldCreateAStateObjectWithDefaultId) {
    State state = State();
    ASSERT_EQ(state.getId(), 0);
}

TEST(StateTest, ItShouldCreateAStateObjectWithId) {
    State state = State(1);
    ASSERT_EQ(state.getId(), 1);
}