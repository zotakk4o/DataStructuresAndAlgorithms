#include "DebugCommand.h"

#include "src/HuffmanDecoder.h"
#include "src/helpers/Helpers.h"
#include "include/File.h"
#include<iostream>

void DebugCommand::execute(Vector<String*>& filesNames) const {
	std::cout << HuffmanDecoder::debug(*filesNames[0]) << std::endl;
	Helpers::exitProgram();
}

String DebugCommand::toString() const {
	return "debug";
}