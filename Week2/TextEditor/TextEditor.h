#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include "include/Stack.cpp"
#include "include/String.h"

class TextEditor
{
	private:
		Stack<char> content;
		Stack<String> toUndo;
		Stack<char> deleted;
	public:
		void append(const String&, const bool& withoutAppending = false);
		void deleteCharacters(unsigned int);
		void print(const unsigned int&);
		void undo();

};

#endif
