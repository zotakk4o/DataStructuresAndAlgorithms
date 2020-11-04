#include "MathHelper.h"
#include "Stack.cpp"

double MathHelper::calculateOperation(const double& first, const double& second, const char& mathOperator) {
	switch (mathOperator) {
	case '*':
		return first * second;
	case '/':
		return first / second;
	case '-':
		return first - second;
	case '+':
		return first + second;
	}
}

double MathHelper::calculateExpression(const String& expr) {
	Stack<double> numbers;
	Stack<char> operators;
	unsigned int exprLength = expr.getLength();
	String currentSymbol;
	String allowedOperators = "/+*-";

	for (size_t i = 0; i < exprLength; i++)
	{
		if (expr[i] == ' ') {
			int isNumeric = String::isNumeric(currentSymbol);

			if (isNumeric == 1) {
				numbers.push(String::toDouble(currentSymbol));
			}
			else if (isNumeric == 0) {
				numbers.push(String::toInt(currentSymbol));
			}

			currentSymbol = "";
			continue;
		}

		if (allowedOperators.indexOf(expr[i]) != -1) {
			operators.push(expr[i]);
		}

		currentSymbol += expr[i];
	}

	numbers.push(String::isNumeric(currentSymbol) == 1 ? String::toDouble(currentSymbol) : String::toInt(currentSymbol));

	while (!operators.isEmpty()) {
		double secondNum = numbers.pop();
		double firstNum = numbers.pop();
		char currOperator = operators.pop();

		if (operators.isEmpty()) {
			return MathHelper::calculateOperation(firstNum, secondNum, currOperator);
		}

		char nextOperator = operators.peek();

		if (nextOperator == '+' || nextOperator == '-' || nextOperator == '*') {
			if (nextOperator == '*') {
				numbers.push(MathHelper::calculateOperation(numbers.pop() * firstNum, secondNum, currOperator));
				operators.pop();
				continue;
			}
			numbers.push(MathHelper::calculateOperation(firstNum, secondNum, currOperator));
			continue;
		}

		Stack<double> helperDivisionStack;
		helperDivisionStack.push(firstNum);
		do {
			nextOperator = operators.pop();
			helperDivisionStack.push(numbers.pop());
		} while (!operators.isEmpty() && operators.peek() != '/');

		double divisionResult = helperDivisionStack.pop();

		while (!helperDivisionStack.isEmpty()) {
			divisionResult /= helperDivisionStack.pop();
		}

		numbers.push(MathHelper::calculateOperation(divisionResult, secondNum, currOperator));
		
	}
 
	return numbers.pop();
}

