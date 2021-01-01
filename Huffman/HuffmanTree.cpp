#include "HuffmanTree.h"
#include "src/config/Errors.h"
#include<queue>
#include<vector>
#include<iostream>

HuffmanTree::HuffmanNode::HuffmanNode(HuffmanNode* const& _left, HuffmanNode* const& _right, const unsigned int& _frequency, const char& _symbol)
	: left(_left), right(_right), frequency(_frequency), symbol(_symbol) {}

bool HuffmanTree::HuffmanNode::operator>(const HuffmanNode& other) const {
	return this->frequency > other.frequency;
}

HuffmanTree::HuffmanTree(const String& input) : root(nullptr) {
	if (input.getLength()) {
		this->buildTree(input);
		this->generateCodes(this->root);
	}
}

void HuffmanTree::buildTree(const String& input) {
	int frequencyTable[256] = { 0 };
	unsigned int inputLength = input.getLength();

	for (unsigned int i = 0; i < inputLength; i++)
	{
		if (input[i] > 255 || input[i] < 0) {
			throw Errors::invalidInput;
		}

		frequencyTable[input[i]]++;
	}

	std::priority_queue < HuffmanNode*, std::vector<HuffmanNode*>, HuffmanTree::Comparator > priorityQueue;

	for (size_t i = 0; i < 256; i++)
	{
		if (frequencyTable[i]) {
			priorityQueue.push(this->getLeaf(frequencyTable[i], i));
		}
	}

	while (priorityQueue.size() != 1)
	{
		HuffmanNode* left = priorityQueue.top(); 
		priorityQueue.pop();
		HuffmanNode* right = priorityQueue.top();	
		priorityQueue.pop();

		unsigned int sum = left->frequency + right->frequency;
		priorityQueue.push(new HuffmanNode(left, right, sum));
	}

	this->root = priorityQueue.top();
}

void HuffmanTree::generateCodes(HuffmanNode* const& root, String code)
{
	if (root == nullptr)
		return;

	if (!root->left && !root->right) {
		this->codes[root->symbol] = code.getLength() ? code :  "0";
	}

	generateCodes(root->left, code + "0");
	generateCodes(root->right, code + "1");
}

void HuffmanTree::deleteTree(HuffmanNode* root) {
	if (!root) {
		return;
	}

	this->deleteTree(root->left);
	this->deleteTree(root->right);

	delete root;
}

HuffmanTree::~HuffmanTree() {
	this->deleteTree(this->root);
}

HuffmanTree::HuffmanNode* HuffmanTree::getLeaf(const unsigned int& frequency, const char& symbol) const {
	HuffmanNode* leaf = new HuffmanNode();
	leaf->symbol = symbol;
	leaf->frequency = frequency;
	return leaf;
}

void HuffmanTree::printCodes() {
	for (unsigned int i = 0; i < 256; i++)
	{
		if (this->codes[i].getLength()) {
			std::cout << (char)i << " -> " << this->codes[i] << std::endl;
		}
	}
}

void HuffmanTree::saveNodes(std::ofstream& stream, HuffmanNode* const& root) const {
	if (!root || !stream) {
		return;
	}

	stream.write(&root->symbol, sizeof(char));

	this->saveNodes(stream, root->left);
	this->saveNodes(stream, root->right);
}

std::ofstream& operator<<(std::ofstream& stream, const HuffmanTree& tree) {
	tree.saveNodes(stream, tree.root);

	return stream;
}

HuffmanTree::HuffmanNode* HuffmanTree::readNodes(std::ifstream& stream) {
	if (!stream) {
		return nullptr;
	}

	char symbol;

	stream.read(&symbol, sizeof(char));
	if (symbol > 255 || symbol < 0) {
		throw Errors::invalidInput;
	}
	HuffmanNode* newNode = new HuffmanNode();
	newNode->symbol = symbol;

	if (!symbol) {
		newNode->left = this->readNodes(stream);
		newNode->right = this->readNodes(stream);
	}
	
	return newNode;
}

std::ifstream& operator>>(std::ifstream& stream, HuffmanTree& tree) {
	tree.root = tree.readNodes(stream);
	tree.generateCodes(tree.root);
	return stream;
}

String HuffmanTree::encode(const String& str) {
	String res = "";

	unsigned int strLength = str.getLength();
	for (unsigned int i = 0; i < strLength; i++)
	{
		if (!this->codes[str[i]].getLength()) {
			throw Errors::invalidSymbol;
		}
		res += this->codes[str[i]];
	}



	return res;
}

void HuffmanTree::decodeInternal(HuffmanNode* const& root, const String& str, unsigned int& index, String& res) {
	if (!root) {
		return;
	}
	
	if (!root->left && !root->right)
	{
		res += root->symbol;
		return;
	}

	if (str[index++] == '0') {
		this->decodeInternal(root->left, str, index, res);
	}
	else {
		this->decodeInternal(root->right, str, index, res);
	}
}

String HuffmanTree::decode(const String& str) {
	String res;
	unsigned int strLength = str.getLength();
	unsigned int index = 0;

	while (index < strLength) {
		this->decodeInternal(this->root, str, index, res);
	}
	return res;
}