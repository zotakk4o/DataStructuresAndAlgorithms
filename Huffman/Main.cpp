#include "src/CommandsProcessor.h"
#include "HuffmanTree.h"
#include<iostream>
int main() {
	//CommandsProcessor processor;
	//processor.start();
	HuffmanTree test("ABRACADAABRA");
	test.printCodes();
	std::ofstream file;
	file.open("test.dat", std::ofstream::binary|std::ofstream::trunc);
	file << test;
	file.close();
	std::ifstream input;
	HuffmanTree test2;
	input.open("test.dat", std::ifstream::binary);
	input >> test2;
	test2.printCodes();
	file.close();
	std::cout << test2.encode("ABRACADABRA") << std::endl;
	std::cout << test2.decode(test2.encode("ABRACADABRA"));
	return 0;
}