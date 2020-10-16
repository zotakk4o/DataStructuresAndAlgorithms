#include<iostream>
#include "include/String.h"
#include "include/Stack.cpp"

int parseArithmeticExpression(const String& expr) {
	Stack<String> elements;
	for (size_t i = 0; i < expr.getLength(); i++)
	{
		if (expr[i] >= '0' && expr[i] <= '9' || expr[i] == '/' || expr[i] == '*' || expr[i] == '+' || expr[i] == '-' || expr[i] == '(') {
			if (expr[i] == '-' && !elements.isEmpty() && elements.peek() == '(') {
				elements.push('-' + expr[i++ + 1]);
			}
			else if (expr[i] >= '0' && expr[i] <= '9' && !elements.isEmpty() && elements.peek() >= '0' && elements.peek() <= '9') {
				elements.push(elements.pop() + expr[i]);
			}
			else {
				elements.push(expr[i]);
			}
		}
		else if (expr[i] == ')') {
			String currElement = elements.pop();
			int currInt = String::toInt(currElement);
			while (currElement != '(') {
				currElement = elements.pop();
				if (currElement == '*') {
					currInt *= String::toInt(elements.pop());
				}
				else if (currElement == '-') {
					currInt -= String::toInt(elements.pop());
				}
				else if (currElement == '/') {
					currInt /= String::toInt(elements.pop());
				}
				else if (currElement == '+') {
					currInt += String::toInt(elements.pop());
				}
			}
			elements.push(String::toString(currInt));
		}
	}

	return String::toInt(elements.pop());
}

int main() {
	std::cout << parseArithmeticExpression("(1 + ((2 + 3) * (3 * 2)))");
	return 0;
}