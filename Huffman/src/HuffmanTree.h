#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "include/String.h"
#include <fstream>

/// <summary>
/// A class representing a Huffman's tree and its properties.
/// </summary>
class HuffmanTree
{
	private:
		struct HuffmanNode
		{
			unsigned char symbol;
			unsigned int frequency;
			HuffmanNode* left, * right;

			HuffmanNode(HuffmanNode* const& = nullptr, HuffmanNode* const& = nullptr, const unsigned int& = 0, const unsigned char& = '\0');
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
		HuffmanNode* getLeaf(const unsigned int&, const unsigned char&) const;
		void deleteTree(HuffmanNode*);
		void saveNodes(std::ofstream&, HuffmanNode* const&) const;
		HuffmanNode* readNodes(std::ifstream&);
		void decodeInternal(HuffmanNode* const&, const String&, unsigned int&, String&);
	public:
		/// <summary>
		/// Default Constructor. Constructor for creating a tree from a text
		/// </summary>
		/// <param>const String& the string to be used for building the tree and generating the codes</param>
		HuffmanTree(const String& = "");
		HuffmanTree(const HuffmanTree&) = delete;
		HuffmanTree& operator=(const HuffmanTree&) = delete;
		~HuffmanTree();

		/// <summary>
		/// Encodes a given string
		/// </summary>
		/// <param>const String& the string to be encoded</param>
		String encode(const String&);

		/// <summary>
		/// Decodes a given BINARY sequence
		/// </summary>
		/// <param>const String& the BINARY sequence to be decoded</param>
		String decode(const String&);

		friend std::ofstream& operator<<(std::ofstream&, const HuffmanTree&);
		friend std::ifstream& operator>>(std::ifstream&, HuffmanTree&);

		/// <summary>
		/// A function for debugging purposes. Prints the code for each letter in the console.
		/// </summary>
		void printCodes();
};

#endif

