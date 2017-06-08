#include "compiler.h"
#include "parser/parser.h"

RegularExpressionCompiler::RegularExpressionCompiler() {

}

NFA RegularExpressionCompiler::compile(const char *expression) {
    RegularExpression expr = RegularExpression(expression);
    return compile(expr);
}

NFA RegularExpressionCompiler::compile(RegularExpression &expression) {
    RegularExpression *expr = preprocessForConcat(expression);

    Parser parser = Parser(*expr);

    std::stack<NFA> constructedNFA;
    std::stack<Operator> operators;
    int nfaCounter = 0;
    while (parser.hasNext()) {
        ParsedToken *parsedToken = parser.readNext();

        if (parsedToken->isLetter()) {
            State start = State(0, nfaCounter);
            State end = State(1, nfaCounter);
            start.addTransition(end, parsedToken->get());
            NFA nfa = NFA(start, end, nfaCounter);
            nfaCounter++;
            constructedNFA.push(nfa);
        }

        if (parsedToken->isOperator()) {
            if (operators.empty() || parsedToken->get() == Operator::LEFT_P) {
                Operator op = Operator(parsedToken->get(), Operator::findPriority(parsedToken->get()));
                operators.push(op);
            } else if (parsedToken->get() == Operator::RIGHT_P) {
                // we matched end of (), we should eval all operators between ( and )

                //make this lambda
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
                // eval if we can and push new op

                //missing eval code here

                Operator currentOperator = Operator(parsedToken->get(), Operator::findPriority(parsedToken->get()));

                while (!operators.empty() && currentOperator.getPriority() <= operators.top().getPriority()) {
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


                operators.push(currentOperator);
            }
        }

        delete parsedToken;
    }

    processOperator(operators, constructedNFA);

    delete expr;
    return constructedNFA.top();

}

RegularExpression *RegularExpressionCompiler::preprocessForConcat(RegularExpression &expression) {
    Parser parser = Parser(expression);

    char *processedExpression = new char[expression.length() * 2];


    int index = 0;
    while (parser.hasNext()) {
        ParsedToken *currentToken = parser.readNext();
        ParsedToken *nextToken = parser.lookNext();

        // ab, a(, *a, *(, )( all result in concat
        processedExpression[index] = currentToken->get();
        if (nextToken != nullptr) {

            if (currentToken->isLetter() && (nextToken->isLetter() || nextToken->get() == Operator::LEFT_P)) {
                // case ab,a(
                processedExpression[++index] = Operator::CONCAT;
            }

            if (currentToken->isOperator()) {
                if (currentToken->get() == Operator::STAR && nextToken->isLetter()) {
                    // *a
                    processedExpression[++index] = Operator::CONCAT;
                }

                if (currentToken->get() == Operator::STAR && nextToken->get() == Operator::LEFT_P) {
                    // *(
                    processedExpression[++index] = Operator::CONCAT;
                }

                if (currentToken->get() == Operator::RIGHT_P &&
                    (nextToken->get() == Operator::LEFT_P || nextToken->isLetter())) {
                    // )( or )a
                    processedExpression[++index] = Operator::CONCAT;
                }

            }
        }
        index += 1;
        delete currentToken;
        delete nextToken;
    }
    processedExpression[index] = '\0';
    RegularExpression *processedRegEx = new RegularExpression(processedExpression);
    delete[] processedExpression;
    return processedRegEx;

}

void RegularExpressionCompiler::processOperator(std::stack<Operator> &operators, std::stack<NFA> &constructedNFA) {
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
}