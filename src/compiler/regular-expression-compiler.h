#ifdef REGULAR_EXPRESSION_COMPILER_H
#define REGULAR_EXPRESSION_COMPILER_H

#import "state-machine/abstract-state-machine.h";

class RegularExpressionCompiler{
public:
	RegularExpressionCompiler();
	RegularExpressionCompiler(RegularExpressionCompiler &regularExpressionCompiler);
	RegularExpressionCompiler(RegularExpression regularExpression);
	AbstractStateMachine& compile();
};

#endif
