#include "gtest/gtest.h"
#include "state-machine/utils/transition.cpp"
#include "state-machine/utils/state.cpp" //why should I include the source file and not the header?

TEST(TransitionTest, ItShouldCreateATransitionObjectFromReference) {
    State mockStateTo = State(2);
    Transition transition = Transition(mockStateTo, 'a');
    ASSERT_TRUE(*transition.getTo() == mockStateTo);
    ASSERT_EQ('a', transition.getLabel());
}

TEST(TransitionTest, ItShouldCreateATransitionObjectFromPointer) {
    State mockStateTo = State(2);
    State *mockStateToPtr = &mockStateTo;
    Transition transition = Transition(mockStateToPtr, 'a');
    ASSERT_TRUE(*transition.getTo() == mockStateTo);
    ASSERT_EQ('a', transition.getLabel());
}