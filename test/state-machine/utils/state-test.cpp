#include "gtest/gtest.h"
#include "state-machine/utils/state.h"

TEST(StateTest, ItShouldCreateAStateObjectWithDefaultId) {
    State state = State();

    ASSERT_EQ(state.getId(), 0);
}

TEST(StateTest, ItShouldCreateAStateObjectWithId) {
    State state = State(1);

    ASSERT_EQ(state.getId(), 1);
}

TEST(StateTest, ItShouldAddTransitionAsObj) {
    State state = State(1);
    State mockState = State(2);
    Transition mockTransition = Transition(&mockState, 'a');
    state.addTransition(mockTransition);

    ASSERT_EQ(state.getTransitions().size(), 1);
}

TEST(StateTest, ItShouldAddTransitionAsStateAndLabel) {
    State state = State(1);
    State mockState = State(2);
    state.addTransition(mockState, 'a');

    ASSERT_EQ(state.getTransitions().size(), 1);
    ASSERT_TRUE(*(state.getTransitions()[0].getTo()) == mockState);
}


TEST(StateTest, ItShouldDeepCopyState) {
    State state = State(1);
    State mockState = State(2);
    state.addTransition(mockState, 'a');
    State testState = State(state);

    ASSERT_EQ(testState.getId(), state.getId());
    ASSERT_FALSE(&state == &testState);
}
