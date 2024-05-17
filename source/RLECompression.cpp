#include "RLECompression.hpp"
#include <iostream>
#include <complex>

std::vector<std::pair<int, std::complex<float>>> RLECompression::compressData(std::vector<std::complex<float>> data) {
    compressedData.clear(); // Clear previous compressed data

    int n = data.size();
    if (n == 0) // If input data is empty, return empty compressed data
        return compressedData;

    int count = 1;
    std::complex<float> prevValue = data[0]; // Initialize with the first value
    int startIdx = 0; // Starting index of the current sequence

    // Iterate over the input data (including one extra iteration for final sequence)
    for (int i = 1; i <= n; ++i) {
        if (i < n && data[i] == prevValue) {
            // If current element is the same as previous value, increment count
            count++;
        } else {
            // Add the current sequence to compressedData
            compressedData.push_back(std::make_pair(count, prevValue));

            if (i < n) {
                // Move to the next sequence
                startIdx = i;
                prevValue = data[i]; // Update previous value
                count = 1;
            }
        }
    }

    return compressedData;
}

std::vector<std::pair<int, std::complex<float>>> RLECompression::getCompressedData() const {
    return compressedData;
}

void RLECompression::printCompressedData() const {
    std::cout << "Printer function - Compressed data: ";
    for (const auto& p : compressedData) {
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }
    std::cout << std::endl;
}

void RLECompression::setAlgorithmParameters() {
    std::cout << "RLC is not parametrizable" << std::endl;
}

std::vector<std::string> RLECompression::getAlgorithmParameters() const {
    return {"Run Length Encoding Compression"};
}
