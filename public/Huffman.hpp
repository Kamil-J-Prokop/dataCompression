#ifndef HUFFMANTREE_HPP
#define HUFFMANTREE_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <memory>

// Custom hash function for std::pair<int, int>
struct PairHash {
    std::size_t operator()(const std::pair<int, int>& p) const;
};

// Custom equality function for std::pair<int, int>
struct PairEqual {
    bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const;
};

// Node structure for Huffman tree
struct Node {
    int freq;
    std::pair<int, int> data;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(int freqParam, std::pair<int, int> dataParam);
};

// Comparator for priority queue
struct Compare {
    bool operator()(const std::shared_ptr<Node>& l, const std::shared_ptr<Node>& r) const;
};

// Function to build Huffman tree
std::shared_ptr<Node> buildHuffmanTree(const std::vector<std::pair<int, int>>& pairs);

// Function to generate Huffman codes
void generateHuffmanCodes(const std::shared_ptr<Node>& root, std::unordered_map<std::pair<int, int>, std::string, PairHash, PairEqual>& codes, std::string code = "");

#endif // HUFFMANTREE_HPP
