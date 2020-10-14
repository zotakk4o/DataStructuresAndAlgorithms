#include<iostream>
#include "include/Stack.cpp"
#include "include/File.h"
#include "include/String.h"

String readDataFromFile(const String& filename) {
	File file{ filename, true };
	return file.getData();
}

bool paranthesesCheck(const String& str) {
	Stack<char> opened;
	unsigned int strLength = str.getLength();

	for (size_t i = 0; i < strLength; i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			opened.push(str[i]);
		}
		else if ((str[i] == '}' || str[i] == ']') && (opened.isEmpty() || opened.pop() != str[i] - 2)) {
			return false;
		}
		else if (str[i] == ')' && (opened.isEmpty() || opened.pop() != str[i] - 1)) {
			return false;
		}

	}

	return opened.isEmpty();
}

int main() {
	std::cout << paranthesesCheck(readDataFromFile("ParenthesesValidator/test-data.txt"));
	return 0;
}