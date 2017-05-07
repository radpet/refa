#include "compiler.h"
#include "parser/parser.h"
#include "parser/token/operator/operator.h"

#include <stack>

RegularExpressionCompiler::RegularExpressionCompiler() {

}

NFA RegularExpressionCompiler::compile(RegularExpression expression) {
    Parser parser = Parser(expression);

    std::stack<NFA> constructedNFA;
    std::stack<Operator> operators;
    while (parser.hasNext()) {
        ParsedToken *parsedToken = parser.readNext();

        if (parsedToken->isLetter()) {
            State start = State(0, 1);
            State end = State(1, 1);
            start.addTransition(end, 'a');
            NFA nfa = NFA(start, end, 1);
            constructedNFA.push(nfa);
        } else {

        }

        delete parsedToken;
    }

    return constructedNFA.top();
}