#include "gtest/gtest.h"
#include "compiler/compiler.h"

//TEST(TestLib, ItConvertRegExToJson) {
//    char regEx[] = "ab";
//    RegularExpressionCompiler regularExpressionCompiler = RegularExpressionCompiler();
//    NFA result = regularExpressionCompiler.compile(regEx);
//
//    result.serialize(std::cout);
//}

TEST(TestLib, ItConvertRegExToJson2) {
    char regEx[] = "a*";
    RegularExpressionCompiler regularExpressionCompiler = RegularExpressionCompiler();
    NFA result = regularExpressionCompiler.compile(regEx);

    result.serialize(std::cout);
}