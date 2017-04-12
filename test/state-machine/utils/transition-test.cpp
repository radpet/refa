#include "gtest/gtest.h"
#include "../src/state-machine/utils/transition.cpp"
#include "../src/state-machine/utils/state.cpp"

TEST(TransitionTest, ItShouldCreateATransitionObject) {
    State mockStateFrom = State(1);
    State mockStateTo = State(2);
    Transition transition = Transition(mockStateFrom, mockStateTo, 'a');
    ASSERT_TRUE(mockStateFrom == transition.getFrom());
    ASSERT_TRUE(mockStateTo == transition.getTo());
    ASSERT_EQ('a', transition.getLabel());
}