#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "include/String.h"
#include <fstream>

class HuffmanTree
{
	private:
		struct HuffmanNode
		{
			char symbol;
			unsigned int frequency;
			HuffmanNode* left, * right;

			HuffmanNode(HuffmanNode* const& = nullptr, HuffmanNode* const& = nullptr, const unsigned int& = 0, const char& = '\0');
			bool operator>(const HuffmanNode&) const;
		};

		struct Comparator
		{
			bool operator()(HuffmanNode* left, HuffmanNode* right)
			{
				return (*left) > (*right);
			}
		};

		HuffmanNode* root;
		String codes[256];

		void buildTree(const String&);
		void generateCodes(HuffmanNode* const&, String = "");
		HuffmanNode* getLeaf(const unsigned int&, const char&) const;
		void deleteTree(HuffmanNode*);
		void saveNodes(std::ofstream&, HuffmanNode* const&) const;
		HuffmanNode* readNodes(std::ifstream&);
		void decodeInternal(HuffmanNode* const&, const String&, unsigned int&, String&);
	public:
		HuffmanTree(const String& = "");
		HuffmanTree(const HuffmanTree&) = delete;
		HuffmanTree& operator=(const HuffmanTree&) = delete;
		~HuffmanTree();

		String encode(const String&);
		String decode(const String&);

		friend std::ofstream& operator<<(std::ofstream&, const HuffmanTree&);
		friend std::ifstream& operator>>(std::ifstream&, HuffmanTree&);
		void printCodes();
};

#endif

