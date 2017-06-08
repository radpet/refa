#include<cstring>
#include "regular-expression/regular-expression.h"


#include "gtest/gtest.h"

bool equalStrings(const char a[], const char b[]) {
    return std::strcmp(a, b) == 0;
}

TEST(RegularExpression, ItShouldCreateRegularExpressionObj) {
    const char *test = "abc";

    RegularExpression expr = RegularExpression(test);


    ASSERT_TRUE(equalStrings(expr.getExpression(), test));
}