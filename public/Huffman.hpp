#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <memory>
#include <complex>
#include <functional> // For std::hash

// Custom hash function for std::pair<int, std::complex<float>>
struct PairHash {
    std::size_t operator()(const std::pair<int, std::complex<float>>& p) const {
        auto h1 = std::hash<int>{}(p.first);
        auto h2 = std::hash<float>{}(p.second.real()); // Hash real part
        auto h3 = std::hash<float>{}(p.second.imag()); // Hash imaginary part
        return h1 ^ h2 ^ h3;
    }
};

// Custom equality function for std::pair<int, std::complex<float>>
struct PairEqual {
    bool operator()(const std::pair<int, std::complex<float>>& lhs, const std::pair<int, std::complex<float>>& rhs) const {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
};

// Node structure for Huffman tree
struct Node {
    int freq;
    std::pair<int, std::complex<float>> data;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(int freqParam, std::pair<int, std::complex<float>> dataParam);
};

// Comparator for priority queue
struct Compare {
    bool operator()(const std::shared_ptr<Node>& l, const std::shared_ptr<Node>& r) const;
};

// Function to build Huffman tree
std::shared_ptr<Node> buildHuffmanTree(const std::vector<std::pair<int, std::complex<float>>>& pairs);

// Function to generate Huffman codes
void generateHuffmanCodes(const std::shared_ptr<Node>& root, std::unordered_map<std::pair<int, std::complex<float>>, std::string, PairHash, PairEqual>& codes, std::string code = "");

#endif // HUFFMAN_HPP
