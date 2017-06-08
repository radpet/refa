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

TEST(RegularExpressionCompiler, ItShouldEvalComplexConcat) {
    char regEx[] = "abc";
    RegularExpressionCompiler regularExpressionCompiler = RegularExpressionCompiler();
    NFA result = regularExpressionCompiler.compile(regEx);

    ASSERT_EQ(result.getStates().size(), 6);
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

TEST(RegularExpressionCompiler, ItShouldEvalComplexRegex) {
    char regEx[] = "a(a|b)b";
    RegularExpressionCompiler regularExpressionCompiler = RegularExpressionCompiler();
    NFA result = regularExpressionCompiler.compile(regEx);

    ASSERT_EQ(result.getStates().size(), 10);
}

TEST(RegularExpressionCompiler, ItShouldEvalComplexRegex2) {
    char regEx[] = "abc(a|b)(b|c)";
    RegularExpressionCompiler regularExpressionCompiler = RegularExpressionCompiler();
    NFA result = regularExpressionCompiler.compile(regEx);

    // abc - > 6, a|b -> 6 b|c 6
    ASSERT_EQ(result.getStates().size(), 18);
}

TEST(RegularExpressionCompiler, ItShouldEvalComplexRegex3) {
    char regEx[] = "a(a|b)*b";
    RegularExpressionCompiler regularExpressionCompiler = RegularExpressionCompiler();
    NFA result = regularExpressionCompiler.compile(regEx);

    ASSERT_EQ(result.getStates().size(), 12);
}

TEST(RegularExpressionCompiler, ItShouldEvalComplexRegex4) {
    char regEx[] = "a|b|c(ab)*";
    RegularExpressionCompiler regularExpressionCompiler = RegularExpressionCompiler();
    NFA result = regularExpressionCompiler.compile(regEx);

    ASSERT_EQ(result.getStates().size(), 16);
}

TEST(RegularExpressionCompiler, ItShouldEvalComplexRegex5) {
    char regEx[] = "a(a|b)";
    RegularExpressionCompiler regularExpressionCompiler = RegularExpressionCompiler();
    NFA result = regularExpressionCompiler.compile(regEx);

    ASSERT_EQ(result.getStates().size(), 8);
}