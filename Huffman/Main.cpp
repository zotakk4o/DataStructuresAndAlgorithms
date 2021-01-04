#include "src/CommandsProcessor.h"
#include "src/HuffmanTree.h"
#include "src/HuffmanEncoder.h"
#include "src/helpers/Helpers.h"
#include "src/HuffmanDecoder.h"

#include<iostream>
int main() {
	//CommandsProcessor processor;
	//processor.start();
	//ABRACAAAAAAAAAADABRAAAAAAAAAAAAAAAAAAAAA ...
	HuffmanEncoder::encode("AAAABBBB", "test2.dat");
	std::cout << HuffmanDecoder::decode("test2.dat");
	return 0;
}