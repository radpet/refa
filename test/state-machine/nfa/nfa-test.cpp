#include "gtest/gtest.h"
#include "state-machine/nfa/nfa.cpp"

TEST(NFA_TEST, ItShouldCreateEmptyNFA) {
    NFA nfa = NFA();
    ASSERT_EQ(nfa.getStates().size(), 0);
    ASSERT_EQ(nfa.getFinalState(), nullptr);
}

TEST(NFA_TEST, ItCreateNFAWithOneState) {
    State a = State(1);
    NFA nfa = NFA(a, a);

    ASSERT_EQ(nfa.getStates().size(), 1);
}

TEST(NFA_TEST, ItShouldDeleteAllStates) {
    State a = State(1);
    NFA *nfa = new NFA(a, a);
    ASSERT_EQ(nfa->getStates().size(), 1);

    delete nfa;

    ASSERT_EQ(nfa->getStates().size(), 0);
}

TEST(NFA_TEST, ItShouldFindState) {
    State a = State(1);
    NFA nfa = NFA(a, a);

    ASSERT_EQ(nfa.getStates().size(), 1);
    ASSERT_TRUE(nfa.hasState(a));
    ASSERT_TRUE(*nfa.findState(a) == a);
}

TEST(NFA_TEST, ItShouldSetFinalState) {
    State finalState = State(1);
    NFA nfa = NFA();
    nfa.setFinalState(finalState);

    ASSERT_TRUE(nfa.hasState(finalState));
    ASSERT_TRUE(nfa.getFinalState() != &finalState);
    ASSERT_TRUE(*nfa.getFinalState() == finalState);
}

TEST(NFA_TEST, ItShouldSetStartState) {
    State startState = State(1);
    NFA nfa = NFA();
    nfa.setStartState(startState);

    ASSERT_TRUE(nfa.hasState(startState));
    ASSERT_TRUE(nfa.getStartState() != &startState);
    ASSERT_TRUE(*nfa.getStartState() == startState);
}

TEST(NFA_TEST, ItShouldConcatAnotherNFA) {
    State a = State(1);
    NFA nfa = NFA(a, a);
    State *nfaFinalStateBeforeConcat = nfa.getFinalState();

    State mockState = State(2);
    NFA mockNFA = NFA(mockState, mockState);
    nfa.concat(mockNFA);

    ASSERT_EQ(nfa.getStates().size(), 2);

    // it should have only 1 eps transition
    // from the final state of the first to the start state of the second

    ASSERT_EQ(nfaFinalStateBeforeConcat->getTransitions()[0]->getLabel(), Transition::EPSILON);
    ASSERT_TRUE(*nfa.getFinalState() == *mockNFA.getStartState());
}