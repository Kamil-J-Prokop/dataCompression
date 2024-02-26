#ifndef HUFFMAN_ENCODING_HPP
#define HUFFMAN_ENCODING_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <memory>

using namespace std;

// Node structure for Huffman tree
struct HuffmanNode {
    int data;
    char character;
    unique_ptr<HuffmanNode> left;
    unique_ptr<HuffmanNode> right;

    HuffmanNode(int d, char c) : data(d), character(c), left(nullptr), right(nullptr) {}
};

// Comparison struct to define priority queue
struct Compare {
    bool operator()(const HuffmanNode* a, const HuffmanNode* b) {
        return a->data > b->data;
    }
};

class HuffmanEncoding {
private:
    unique_ptr<HuffmanNode> root;

    // Helper function to generate Huffman tree
    void generateHuffmanTree(const vector<pair<int, char>>& frequencies);

    // Helper function to build codebook
    void buildCodebook(HuffmanNode* node, string code, unordered_map<char, string>& codebook);

public:
    // Constructor
    HuffmanEncoding(const vector<pair<int, char>>& frequencies);

    // Encode function
    string encode(const string& input);
};

#endif // HUFFMAN_ENCODING_HPP
