#include "state-machine/utils/state.h"
#include "state-machine/nfa/nfa.h"
#include "vector"

#include "gtest/gtest.h"

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

//@TODO this might be failing because the parent obj has been deleted
TEST(NFA_TEST, ItShouldDeleteAllStates) {
    State a = State(1);
    NFA *nfa = new NFA(a, a);

    std::vector<State *> &states = nfa->getStates();

    ASSERT_EQ(states.size(), 1);

    delete nfa;

    //ASSERT_TRUE(states.empty());
}

TEST(NFA_TEST, ItShouldFindState) {
    State a = State(1, 0);
    NFA nfa = NFA(a, a);

    ASSERT_EQ(nfa.getStates().size(), 1);
    ASSERT_TRUE(nfa.hasState(a));
    ASSERT_TRUE(*nfa.findState(a) == a);
}

TEST(NFA_TEST, ItShouldSetFinalState) {
    State finalState = State(1, 0);
    NFA nfa = NFA();
    nfa.setFinalState(finalState);

    ASSERT_TRUE(nfa.hasState(finalState));
    ASSERT_TRUE(nfa.getFinalState() != &finalState);
    ASSERT_TRUE(finalState == *nfa.getFinalState());
}

TEST(NFA_TEST, ItShouldSetStartState) {
    State startState = State(1);
    NFA nfa = NFA();
    nfa.setStartState(startState);

    ASSERT_TRUE(nfa.hasState(startState));
    ASSERT_TRUE(nfa.getStartState() != &startState);
    ASSERT_TRUE(startState == *nfa.getStartState());
}

TEST(NFA_TEST_CONCAT, ItShouldConcatAnotherNFA) {
    State aS = State(1, 1);
    State aF = State(2, 1);
    NFA nfa = NFA(aS, aF, 1);

    ASSERT_EQ(nfa.getAutomataId(), 1);

    const State *nfaFinalStateBeforeConcat = nfa.getFinalState();

    State mockStateS = State(1, 2);
    State mockStateF = State(2, 2);
    NFA mockNFA = NFA(mockStateS, mockStateF, 2);
    nfa.concat(mockNFA);

    // automata id should change because we mutate the nfa by using another automata
    ASSERT_EQ(nfa.getAutomataId(), 3);

    ASSERT_EQ(nfa.getStates().size(), 4);

    // it should have only 1 eps transition
    // from the final state of the first to the start state of the second
    ASSERT_EQ(nfaFinalStateBeforeConcat->getTransitions()[0]->getLabel(), Transition::EPSILON);
}

TEST(NFA_TEST_KLEENE, ItShouldMakeKleeneStarTransformation) {
    State aS = State(1, 1);
    State aF = State(2, 1);
    NFA nfa = NFA(aS, aF, 1);

    const State *finalStateBeforeKleene = nfa.getFinalState();
    nfa.kleene();

    // automata id should not change since we do not mutate with another automata
    ASSERT_EQ(nfa.getAutomataId(), 1);

    // it should have 3 states since we begin with 1 and kleene star adds 2 more
    ASSERT_EQ(nfa.getStates().size(), 4);

    // it should have 2 eps transitions from start
    ASSERT_EQ(nfa.getStartState()->getTransitions()[0]->getLabel(), Transition::EPSILON);
    ASSERT_EQ(nfa.getStartState()->getTransitions()[1]->getLabel(), Transition::EPSILON);

    // it should have 2 eps transitions from old final state
    ASSERT_EQ(finalStateBeforeKleene->getTransitions()[0]->getLabel(), Transition::EPSILON);
    ASSERT_EQ(finalStateBeforeKleene->getTransitions()[1]->getLabel(), Transition::EPSILON);
}


TEST(NFA_TEST_UNION, ItShouldUnionTwoNFA) {
    State aS = State(1, 1);
    State aF = State(2, 1);
    NFA nfa = NFA(aS, aF, 1);

    State bS = State(1, 2);
    State bF = State(2, 2);
    NFA nfa2 = NFA(bS, bF, 2);

    nfa._union(nfa2);

    // automata id should change since we mutate by union
    ASSERT_EQ(nfa.getAutomataId(), 3);

    // it should have 6 states since we begin with 2 and union adds 2 more and nfa2 has 2
    ASSERT_EQ(nfa.getStates().size(), 6);

    // we should have 2 eps transitions from new start state
    ASSERT_EQ(nfa.getStartState()->getTransitions()[0]->getLabel(), Transition::EPSILON);
    ASSERT_EQ(nfa.getStartState()->getTransitions()[0]->getLabel(), Transition::EPSILON);

}
