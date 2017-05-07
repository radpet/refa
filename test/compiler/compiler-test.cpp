#include "compiler/compiler.h"
#include "gtest/gtest.h"

RegularExpressionCompiler createCompiler(char regEx[]) {

}

TEST(RegularExpressionCompiler, ItShouldCompileAToNFA) {
    char regEx[] = "a";
    RegularExpressionCompiler regularExpressionCompiler = RegularExpressionCompiler();
    NFA result = regularExpressionCompiler.compile(regEx);
    ASSERT_EQ(result.getStates().size(), 2);
}