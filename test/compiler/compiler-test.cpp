#include "compiler/compiler.h"
#include "gtest/gtest.h"

TEST(RegularExpressionCompiler, ItShouldCompileAToNFA) {
    char regEx[] = "a";
    RegularExpressionCompiler regularExpressionCompiler = RegularExpressionCompiler();
    NFA result = regularExpressionCompiler.compile(regEx);
    ASSERT_EQ(result.getStates().size(), 2);
    ASSERT_EQ(result.getStartState()->getTransitions()[0]->getLabel(), 'a');
}

TEST(RegularExpressionCompiler, ItShouldEvalConcat) {
    char regEx[] = "ab";
    RegularExpressionCompiler regularExpressionCompiler = RegularExpressionCompiler();
    NFA result = regularExpressionCompiler.compile(regEx);

    ASSERT_EQ(result.getStates().size(), 4);
}

TEST(RegularExpressionCompiler, ItShouldEvalUnion) {
    char regEx[] = "a|b";
    RegularExpressionCompiler regularExpressionCompiler = RegularExpressionCompiler();
    NFA result = regularExpressionCompiler.compile(regEx);

    ASSERT_EQ(result.getStates().size(), 6);
}

TEST(RegularExpressionCompiler, ItShouldEvalKleeneStar) {
    char regEx[] = "a*";
    RegularExpressionCompiler regularExpressionCompiler = RegularExpressionCompiler();
    NFA result = regularExpressionCompiler.compile(regEx);

    ASSERT_EQ(result.getStates().size(), 4);
}

TEST(RegularExpressionCompiler, ItShouldEvalComplexUnion) {
    char regEx[] = "a|b*";
    RegularExpressionCompiler regularExpressionCompiler = RegularExpressionCompiler();
    NFA result = regularExpressionCompiler.compile(regEx);

    ASSERT_EQ(result.getStates().size(), 8);
}

TEST(RegularExpressionCompiler, ItShouldEvalEverythingBetweenLeftPRightP1) {
    char regEx[] = "(ab)";
    RegularExpressionCompiler regularExpressionCompiler = RegularExpressionCompiler();
    NFA result = regularExpressionCompiler.compile(regEx);

    ASSERT_EQ(result.getStates().size(), 4);
}

TEST(RegularExpressionCompiler, ItShouldEvalEverythingBetweenLeftPRightP2) {
    char regEx[] = "(a*)";
    RegularExpressionCompiler regularExpressionCompiler = RegularExpressionCompiler();
    NFA result = regularExpressionCompiler.compile(regEx);

    ASSERT_EQ(result.getStates().size(), 4);
}

TEST(RegularExpressionCompiler, ItShouldEvalEverythingBetweenLeftPRightP3) {
    char regEx[] = "(a*b)";
    RegularExpressionCompiler regularExpressionCompiler = RegularExpressionCompiler();
    NFA result = regularExpressionCompiler.compile(regEx);

    ASSERT_EQ(result.getStates().size(), 6);
}
