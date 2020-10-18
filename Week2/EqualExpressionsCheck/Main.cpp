#include "include/MathHelper.h"
#include "include/Stack.cpp"
#include "include/String.h"
#include<iostream>

int main() {
	String expression;
	String::getLine(std::cin, expression);
	Vector<String> expressions = expression.split(" = ");
	int correct = 0;
	unsigned int expressionsCount = expressions.getSize();
	double result = String::isNumeric(expressions[expressionsCount - 1]) == 1
		? String::toDouble(expressions[expressionsCount - 1])
		: String::toInt(expressions[expressionsCount - 1]);

	for (size_t i = 0; i < expressionsCount - 1; i++)
	{	
		if (MathHelper::calculateExpression(expressions[i]) == result) {
			correct++;
		}
	}

	std::cout << correct << "/" << expressionsCount - 1;

	return 0;
}