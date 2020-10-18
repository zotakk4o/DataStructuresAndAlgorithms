#include "TextEditor.h"
#include<iostream>

int main() {
	TextEditor test;
	test.append("TestText");
	test.print(0);
	test.print(1);
	test.deleteCharacters(4);
	test.print(4);
	test.undo();
	test.print(4);
	test.undo();
	test.print(4);
	return 0;
}