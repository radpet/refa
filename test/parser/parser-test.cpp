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
    ParsedToken *token = parser.readNext();
    ASSERT_FALSE(parser.hasNext());

    delete token;
}

TEST(ParserTest, RegExShouldGetNextAndHasNext) {
    char regEx[] = "ab";
    RegularExpression mock = RegularExpression(regEx);
    Parser parser = Parser(mock);
    ParsedToken *token = parser.readNext();
    ASSERT_TRUE(parser.hasNext());

    delete token;
}

TEST(ParserTest, ItShouldGetLetter) {
    char regEx[] = "a";
    RegularExpression mock = RegularExpression(regEx);
    Parser parser = Parser(mock);;
    ParsedToken *token = parser.readNext();
    ASSERT_TRUE(token->isLetter());

    delete token;
}

TEST(ParserTest, ItShouldGetOperator) {
    char regEx[] = "a|b";
    RegularExpression mock = RegularExpression(regEx);
    Parser parser = Parser(mock);
    parser.readNext();
    ParsedToken *token = parser.readNext();
    ASSERT_TRUE(token->isOperator());

    delete token;
}

TEST(ParserTest, ItShouldReadNext) {
    char regEx[] = "a|b";
    RegularExpression mock = RegularExpression(regEx);
    Parser parser = Parser(mock);
    int position = 0;
    while (parser.hasNext()) {
        ParsedToken *token = parser.readNext();
        ASSERT_EQ(token->get(), regEx[position]);
        position += 1;
        delete token;
    }
}

TEST(ParserTest, ItShouldOnlyLookAheadForNextToken) {
    char regEx[] = "a";
    RegularExpression mock = RegularExpression(regEx);
    Parser parser = Parser(mock);

    ParsedToken *token = parser.lookNext();

    ASSERT_EQ(token->get(), 'a');
    ASSERT_TRUE(parser.hasNext());

    delete token;

    token = parser.readNext();
    ASSERT_EQ(token->get(), 'a');
    ASSERT_FALSE(parser.hasNext());

}