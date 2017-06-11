#include "state-machine/utils/state.h"
#include "state-machine/utils/transition.h"
#include <iostream>


#include "gtest/gtest.h"

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
    char mockLabel = 'a';
    Transition mockTransition = Transition(&mockState, mockLabel);
    state.addTransition(mockTransition);

    ASSERT_EQ(state.getTransitions().size(), 1);
}

TEST(StateTest, ItShouldAddTransitionAsStateAndLabel) {
    State state = State(1, 1);
    State mockState = State(2, 1);
    state.addTransition(mockState, 'a');

    ASSERT_EQ(state.getTransitions().size(), 1);
    ASSERT_TRUE(mockState == *(state.getTransitions()[0]->getTo()));
}

TEST(StateTest, ItShouldDeepCopyState) {
    State state = State(1);
    State testState = State(state);

    ASSERT_EQ(testState.getId(), state.getId());
}

TEST(StateTest, ItShouldSerializeState) {
    State state = State(1, 1);
    State mockState = State(2, 1);
    state.addTransition(mockState, 'a');

    std::string result = std::string("{\n") +
                         "\"id1\":\"1\",\n" +
                         "\"id2\":\"1\",\n" +
                         "\"transitions\":[{\n" +
                         "\"id1\":\"2\",\n" +
                         "\"id2\":\"1\",\n" +
                         "\"transitions\":[]\n" +
                         "}]\n" +
                         "}\0";

    // should check if this is optimized on compile
    char buffer[result.length()];

    std::stringstream stream;
    stream.rdbuf()->pubsetbuf(buffer, sizeof(buffer));

    state.serialize(stream);

    std::ostringstream os;
    os << stream.rdbuf();

    for (int i = 0; i < result.length(); i++) {
        ASSERT_EQ(result[i], os.str()[i]);
    }

}
