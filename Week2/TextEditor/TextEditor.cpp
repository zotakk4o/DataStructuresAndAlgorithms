#include "TextEditor.h"
#include <string.h>
#include <iostream>
void TextEditor::append(const String& str, const bool& withoutAppending) {
	unsigned int strLength = str.getLength();
	for (size_t i = 0; i < strLength; i++)
	{
		this->content.push(str[i]);
	}

	if (!withoutAppending) {
		this->toUndo.push(str + 'a');
	}
	
}

void TextEditor::deleteCharacters(unsigned int charactersToDelete) {
	String str;

	while (charactersToDelete--) {
		str += this->content.pop();
	}

	this->toUndo.push(str + 'd');
}

void TextEditor::print(const unsigned int& index) {
	String searchedString;
	while (!this->content.isEmpty()) {
		searchedString += this->content.pop();
	}

	unsigned int searchedStringLength = searchedString.getLength();
	if (searchedStringLength - index - 1 >= searchedStringLength) {
		std::cout << "Empty" << std::endl;
	}
	else {
		std::cout << searchedString[searchedString.getLength() - index - 1] << std::endl;
	}
	
	this->append(searchedString.reverse(), true);
}

void TextEditor::undo() {
	if (this->toUndo.isEmpty()) {
		return;
	}

	String str = this->toUndo.pop();
	unsigned int strLength = str.getLength();

	if (str[strLength - 1] == 'd') {
		this->append(str.substring(0, strLength - 1).reverse(), true);
		return;
	}

	this->deleteCharacters(strLength - 1);

}