#include "gtest/gtest.h"
#include "state-machine/nfa/nfa.cpp"

TEST(NFATest, ItShouldCreateEmptyNFA) {
    NFA nfa = NFA();
    ASSERT_EQ(nfa.getStates().size(), 0);
    ASSERT_EQ(nfa.getFinalState(), nullptr);
}


TEST(NFATest, ItShouldConcatAnotherNFA) {
    State a = State(1);
    NFA nfa = NFA(a, a);

    State mockState = State(2);
    NFA mockNFA = NFA(mockState, mockState);
    nfa.concat(mockNFA);

    ASSERT_EQ(nfa.getStates().size(), 2);

    //it should have only 1 eps transition
    ASSERT_EQ(nfa.getStartState()->getTransitions()[0].getLabel(), Transition::EPSILON);

}