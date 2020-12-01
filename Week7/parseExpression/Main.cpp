#include <string>
#include <iostream>
#include "include/BTree.cpp"
#include "include/Vector.cpp"
#include <utility>

bool isOperand(const char& symbol) {
	return symbol == '+' || symbol == '*' || symbol == '/' || symbol == '-';
}

bool isNumeric(const char& symbol) {
	return (symbol - '0') < 10 && (symbol - '0') >= 0;
}

BTree<char> parseExpression(const std::string& s) {
	BTree<char> res;
	size_t i = 0;
	char left;
	while(s[++i] != ')') {
		if (s[i] == '(') {
			size_t endI = i;
			while (s[++endI] != ')') {}
			BTree<char> inner = parseExpression(s.substr(i, endI - i));
			if (!res.rootPosition()) {
				res.insert(s[++endI]);
				BTree<char>::leftJoinTrees(res.rootPosition(), inner);
			}
			else {
				BTree<char>::rightJoinTrees(res.rootPosition(), inner);
			}

			i = endI;
		} else if (isNumeric(s[i]) && !res.rootPosition().left()) {
			left = s[i];
		} else if (isOperand(s[i])) {
			res.insert(s[i]);
			res.insert(left);
		}
		else if (isNumeric(s[i])) {
			res.insert(s[i]);
			return res;
		}
	}

	return res;
}

int main() {
	parseExpression("(1*(2+3))").prittyPrint();
	parseExpression("((1+0)*(2+3))").prittyPrint();
	parseExpression("((2+3)*1)").prittyPrint();
	parseExpression("(3*1)").prittyPrint();
	return 0;
}