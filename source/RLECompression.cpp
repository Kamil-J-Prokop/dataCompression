#include "RLECompression.hpp"
#include <iostream>

std::vector<std::pair<int, int>> RLECompression::compressData(std::vector<int> data) {
    compressedData.clear(); // Clear previous compressed data

    int n = data.size();
    if (n == 0) // If input data is empty, return empty compressed data
        return compressedData;

    int count = 1;
    for (int i = 1; i < n; ++i) {
        if (data[i] == data[i - 1]) {
            count++;
        } else {
            compressedData.push_back(std::make_pair(data[i - 1], count));
            count = 1;
        }
    }
    // Add the last element and its count
    compressedData.push_back(std::make_pair(data[n - 1], count));

    return compressedData;
}

std::vector<std::pair<int, int>> RLECompression::getCompressedData() const {
    return compressedData;
}

void RLECompression::printCompressedData() const {
    std::cout << "Printer function - Compressed data: ";
        for (const auto& p : compressedData) {
            std::cout << "(" << p.first << ", " << p.second << ") ";
        }
    std::cout << std::endl;
}

void RLECompression::setAlgorithmParameters(){
    std::cout << "RLC is not parametrizable";
}

std::vector<std::string> RLECompression::getAlgorithmParameters() const{
    return {"Run Length Encoding Compression"};
}