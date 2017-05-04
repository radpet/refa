#include<cstring>
#include "regular-expression/regular-expression.h"


#include "gtest/gtest.h"

bool equalStrings(char a[], char b[]) {
    return std::strcmp(a, b) == 0;
}

TEST(RegularExpression, ItShouldCreateRegularExpressionObj) {
    char test[] = "abc";

    RegularExpression expr = RegularExpression(test);

    ASSERT_TRUE(equalStrings(expr.getExpression(), test));
}