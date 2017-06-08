#include "state-machine/utils/transition.h"
#include "state-machine/utils/state.h"

#include "gtest/gtest.h"

TEST(TransitionTest, ItShouldCreateATransitionObjectFromReference) {
    State mockStateTo = State(2);
    Transition transition = Transition(mockStateTo, 'a');
    ASSERT_TRUE(mockStateTo == *transition.getTo());
    ASSERT_EQ('a', transition.getLabel());
}

TEST(TransitionTest, ItShouldCreateATransitionObjectFromPointer) {
    State mockStateTo = State(2);
    State *mockStateToPtr = &mockStateTo;
    Transition transition = Transition(mockStateToPtr, 'a');
    ASSERT_TRUE(mockStateTo == *transition.getTo());
    ASSERT_EQ('a', transition.getLabel());
}

TEST(TransitionTest, ItShouldDeepCopyState) {
    State mockStateTo = State(2);
    State *mockStateToPtr = &mockStateTo;
    Transition transition = Transition(mockStateToPtr, 'a');
    ASSERT_TRUE(mockStateTo == *transition.getTo());
    ASSERT_TRUE(transition.getTo() != mockStateToPtr);
    ASSERT_EQ('a', transition.getLabel());
}

