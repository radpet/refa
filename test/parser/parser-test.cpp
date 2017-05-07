#include "regular-expression/regular-expression.h"
#include "parser/parser.h"
#include "parser/token/parsed-token.h"

#include "gtest/gtest.h"


TEST(ParserTest, ItShouldCreateParserWithRegExSource) {
    char regEx[] = "a";
    RegularExpression mock = RegularExpression(regEx);
    Parser parser = Parser(mock);
    ASSERT_EQ(parser.getRegex()->getExpression(), mock.getExpression());
}

TEST(ParserTest, EmptyRegExShouldNotHaveNext) {
    char regEx[] = "";
    RegularExpression mock = RegularExpression(regEx);
    Parser parser = Parser(mock);
    ASSERT_FALSE(parser.hasNext());
}

TEST(ParserTest, RegExShouldHaveNext) {
    char regEx[] = "a";
    RegularExpression mock = RegularExpression(regEx);
    Parser parser = Parser(mock);
    ASSERT_TRUE(parser.hasNext());
}

TEST(ParserTest, RegExShouldGetNextAndNotHasNext) {
    char regEx[] = "a";
    RegularExpression mock = RegularExpression(regEx);
    Parser parser = Parser(mock);
    parser.readNext();
    ASSERT_FALSE(parser.hasNext());
}

TEST(ParserTest, RegExShouldGetNextAndHasNext) {
    char regEx[] = "ab";
    RegularExpression mock = RegularExpression(regEx);
    Parser parser = Parser(mock);
    parser.readNext();
    ASSERT_TRUE(parser.hasNext());
}

TEST(ParserTest, ItShouldGetLetter) {
    char regEx[] = "a";
    RegularExpression mock = RegularExpression(regEx);
    Parser parser = Parser(mock);;
    ParsedToken *token = parser.readNext();
    ASSERT_TRUE(token->isLetter());
}

TEST(ParserTest, ItShouldGetOperator) {
    char regEx[] = "a|b";
    RegularExpression mock = RegularExpression(regEx);
    Parser parser = Parser(mock);
    parser.readNext();
    ParsedToken *token = parser.readNext();
    ASSERT_TRUE(token->isOperator());
}