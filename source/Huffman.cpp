#include "Huffman.hpp"

// Node constructor
Node::Node(int freqParam, std::pair<int, std::complex<float>> dataParam)
    : freq(freqParam), data(dataParam), left(nullptr), right(nullptr) {}

// Comparator for priority queue
bool Compare::operator()(const std::shared_ptr<Node>& l, const std::shared_ptr<Node>& r) const {
    return l->freq > r->freq; // Assuming you want to prioritize nodes with higher frequency
}

// Function to build Huffman tree
std::shared_ptr<Node> buildHuffmanTree(const std::vector<std::pair<int, std::complex<float>>>& pairs) {
    std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, Compare> pq;

    for (const auto& pair : pairs) {
        pq.push(std::make_shared<Node>(1, pair)); // Frequency doesn't matter for building the tree
    }

    while (pq.size() > 1) {
        auto left = pq.top();
        pq.pop();
        auto right = pq.top();
        pq.pop();

        auto newNode = std::make_shared<Node>(left->freq + right->freq, std::make_pair(-1, std::complex<float>())); // Dummy pair for internal nodes
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    return pq.top();
}

// Function to generate Huffman codes
void generateHuffmanCodes(const std::shared_ptr<Node>& root, std::unordered_map<std::pair<int, std::complex<float>>, std::string, PairHash, PairEqual>& codes, std::string code) {
    if (!root->left && !root->right) {
        codes[root->data] = code;
        return;
    }

    if (root->left) {
        generateHuffmanCodes(root->left, codes, code + "0");
    }

    if (root->right) {
        generateHuffmanCodes(root->right, codes, code + "1");
    }
}
