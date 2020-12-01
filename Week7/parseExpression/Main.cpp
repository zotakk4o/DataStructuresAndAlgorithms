#include <string>
#include <iostream>
#include "include/BST.cpp"
#include "include/Vector.cpp"
#include <utility>

bool isOperand(const char& symbol) {
	return symbol == '+' || symbol == '*' || symbol == '/' || symbol == '-';
}

bool isNumeric(const char& symbol) {
	return (symbol - '0') < 10 && (symbol - '0') >= 0;
}

BST<unsigned int, char> parseExpression(const std::string& s) {
}

int main() {
	return 0;
}