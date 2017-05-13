#include "compiler.h"
#include "parser/parser.h"
#include "parser/token/operator/operator.h"

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
            start.addTransition(end, parsedToken->get());
            NFA nfa = NFA(start, end, 1);
            constructedNFA.push(nfa);
        } else if (parsedToken->isOperator()) {
            if (operators.empty() || parsedToken->get() == Operator::LEFT_P) {
                Operator op = Operator(parsedToken->get());
                operators.push(op);
            } else if (parsedToken->get() == Operator::RIGHT_P) {
                // we matched () we should eval all operators between ( and )

                while (!operators.empty() && operators.top().getValue() != Operator::LEFT_P) {
                    Operator op = operators.top();
                    NFA nfa = constructedNFA.top();

                    constructedNFA.pop();
                    operators.pop();

                    switch (op.getValue()) {
                        case Operator::STAR: {
                            nfa.kleene();
                            constructedNFA.push(nfa);
                            break;
                        }
                        case Operator::UNION: {
                            NFA other = constructedNFA.top();
                            constructedNFA.pop();
                            nfa._union(other);
                            constructedNFA.push(nfa);
                            break;
                        }
                        case Operator::CONCAT: {
                            NFA previous = constructedNFA.top();
                            constructedNFA.pop();
                            previous.concat(nfa);
                            constructedNFA.push(previous);
                            break;
                        }
                    }
                }

                operators.pop();
            } else {
                // eval everything
                // and put it in the stack

                while (!operators.empty()) {
                    Operator op = operators.top();
                    NFA nfa = constructedNFA.top();

                    constructedNFA.pop();
                    operators.pop();

                    switch (op.getValue()) {
                        case Operator::STAR: {
                            nfa.kleene();
                            constructedNFA.push(nfa);
                            break;
                        }
                        case Operator::UNION: {
                            NFA other = constructedNFA.top();
                            constructedNFA.pop();
                            nfa._union(other);
                            constructedNFA.push(nfa);
                            break;
                        }
                        case Operator::CONCAT: {
                            NFA previous = constructedNFA.top();
                            constructedNFA.pop();
                            previous.concat(nfa);
                            constructedNFA.push(previous);
                            break;
                        }
                    }
                }

                Operator op = Operator(parsedToken->get());
                operators.push(op);
            }
        } else {
            // if it is not operator or input letter what is it?
        }

        while (!operators.empty()) {
            Operator op = operators.top();
            NFA nfa = constructedNFA.top();

            constructedNFA.pop();
            operators.pop();

            switch (op.getValue()) {
                case Operator::STAR: {
                    nfa.kleene();
                    constructedNFA.push(nfa);
                    break;
                }
                case Operator::UNION: {
                    NFA other = constructedNFA.top();
                    constructedNFA.pop();
                    nfa._union(other);
                    constructedNFA.push(nfa);
                    break;
                }
                case Operator::CONCAT: {
                    NFA previous = constructedNFA.top();
                    constructedNFA.pop();
                    previous.concat(nfa);
                    constructedNFA.push(previous);
                    break;
                }
            }
        }

        delete parsedToken;
    }

    return constructedNFA.top();
}

void RegularExpressionCompiler::preprocessForConcat(RegularExpression &expression) {
    Parser parser = Parser(expression);

    while (parser.hasNext()) {
        ParsedToken *currentToken = parser.readNext();
        ParsedToken *nextToken = parser.lookNext();



        delete currentToken;
        delete nextToken;
    }
}

void RegularExpressionCompiler::processOperator(std::stack<Operator> &operators, std::stack<NFA> &constructedNFA) {

}