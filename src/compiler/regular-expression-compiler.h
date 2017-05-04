#ifdef REGULAR_EXPRESSION_COMPILER_H
#define REGULAR_EXPRESSION_COMPILER_H

class RegularExpressionCompiler{
public:
	RegularExpressionCompiler();
	RegularExpressionCompiler(RegularExpressionCompiler &regularExpressionCompiler);
	RegularExpressionCompiler(RegularExpression regularExpression);
};

#endif
