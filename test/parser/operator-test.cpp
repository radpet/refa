#include "parser/operator.h"

#include "gtest/gtest.h"

TEST(OperatorTest, ItShouldCheckIfKleeneStarIsOperator) {
    char test = '*';
    ASSERT_TRUE(Operator::canBeOperator(test));
}

TEST(OperatorTest, ItShouldCheckIfUnionIsOperator) {
    char test = '|';
    ASSERT_TRUE(Operator::canBeOperator(test));
}

TEST(OperatorTest, ItShouldCheckIfLetterIsOperator) {
    char test = 'a';
    ASSERT_FALSE(Operator::canBeOperator(test));
}