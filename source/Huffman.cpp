#include "Huffman.hpp"
#include <cstddef> // Explicitly include <cstddef> for std::size_t

std::size_t PairHash::operator()(const std::pair<int, int>& p) const {
    auto h1 = std::hash<int>{}(p.first);
    auto h2 = std::hash<int>{}(p.second);
    return h1 ^ h2;
}

bool PairEqual::operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const {
    return lhs.first == rhs.first && lhs.second == rhs.second;
}

Node::Node(int freqParam, std::pair<int, int> dataParam) {
    this->freq = freqParam;
    this->data = dataParam;
    left = nullptr;
    right = nullptr;
}

bool Compare::operator()(const std::shared_ptr<Node>& l, const std::shared_ptr<Node>& r) const {
    return l->freq > r->freq;
}

std::shared_ptr<Node> buildHuffmanTree(const std::vector<std::pair<int, int>>& pairs) {
    std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, Compare> pq;

    for (const auto& pair : pairs) {
        pq.push(std::make_shared<Node>(pair.second, pair));
    }

    while (pq.size() > 1) {
        auto left = pq.top();
        pq.pop();
        auto right = pq.top();
        pq.pop();

        auto newNode = std::make_shared<Node>(left->freq + right->freq, left->data);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    return pq.top();
}

void generateHuffmanCodes(const std::shared_ptr<Node>& root, std::unordered_map<std::pair<int, int>, std::string, PairHash, PairEqual>& codes, std::string code) {
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
