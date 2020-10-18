#include "include/MathHelper.h"
#include "include/Stack.h"
#include "include/String.h"
#include<iostream>

int main() {
	String expression;
	String currentNumber;
	String resultExpression;
	String operators = "-+/*";
	unsigned int operatorIndex = 0;
	String::getLine(std::cin, expression);

	unsigned int exprLength = expression.getLength();
	for (size_t i = 0; i < exprLength - operatorIndex; i++)
	{
		if (expression[i] == ' ') {
			resultExpression += resultExpression.getLength() == 0 
				?  currentNumber + ' ' + expression[exprLength - 1 - operatorIndex]
				: String{ ' ' } + currentNumber + ' ' + expression[exprLength - 1 - operatorIndex];
			currentNumber = "";
			operatorIndex += 2;
			continue;
		}

		if (operators.indexOf(expression[i]) == -1) {
			currentNumber += expression[i];
		}
	}

	resultExpression += String{ ' ' } + currentNumber;

	std::cout << String{ "Original expression: " } +resultExpression << std::endl;
	std::cout << MathHelper::calculateExpression(resultExpression);

	return 0;
}