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
    void generateHuffmanTree(const vector<pair<int, char>>& frequencies) {
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

        // Create nodes for each frequency
        for (const auto& freq : frequencies) {
            pq.push(new HuffmanNode(freq.first, freq.second));
        }

        // Build Huffman tree
        while (pq.size() > 1) {
            auto left = pq.top();
            pq.pop();
            auto right = pq.top();
            pq.pop();

            auto newNode = new HuffmanNode(left->data + right->data, '#');
            newNode->left.reset(left); // Transfer ownership
            newNode->right.reset(right); // Transfer ownership
            pq.push(newNode); // Use raw pointer
        }

        root.reset(pq.top()); // Transfer ownership
    }

    // Helper function to build codebook
    void buildCodebook(HuffmanNode* node, string code, unordered_map<char, string>& codebook) {
        if (!node)
            return;

        if (node->character != '#') {
            codebook[node->character] = code;
        }

        buildCodebook(node->left.get(), code + "0", codebook); // Use get() to access raw pointer
        buildCodebook(node->right.get(), code + "1", codebook); // Use get() to access raw pointer
    }

public:
    // Constructor
    HuffmanEncoding(const vector<pair<int, char>>& frequencies) {
        generateHuffmanTree(frequencies);
    }

    // Encode function
    string encode(const string& input) {
        unordered_map<char, string> codebook;
        buildCodebook(root.get(), "", codebook); // Use get() to access raw pointer

        string encoded = "";
        for (char c : input) {
            encoded += codebook[c];
        }
        return encoded;
    }
};
