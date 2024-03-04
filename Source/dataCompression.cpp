#include <iostream>
#include <vector>
#include <string>
#include <list>

#include "Public/ICompression.hpp"
#include "Public/IDecompression.hpp"
#include "Public/RunLengthEncodingCompression.hpp"
#include "Public/HuffmanEncoding.hpp"
//#include "DataHandler.hpp"
//#include "MultiThreadedCompression.hpp"

using namespace std;


int main()
{
    
    vector<int> input = {1, 4, 3, 5, 3, 3, 3, 3 , 3, 3, 3, 2, 1, 5, 4, 3, 5, 6, 7, 7, 7, 7, 7, 1, 4, 3, 5, 3, 3, 3, 3, 3, 3, 3, 2, 1, 5, 4, 3, 5, 6, 7, 7, 7, 7, 7,7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
    //DataHandler obj1l(input);
    RunLengthEncodingCompression<vector<int>> obj1;
    obj1.compressData(input);
    obj1.printCompressedData();

    vector<pair<int, char>> frequencies = {{5, 'a'}, {9, 'b'}, {12, 'c'}, {13, 'd'}, {16, 'e'}, {45, 'f'}};
    HuffmanEncoding huffman(frequencies);

    //string input1 = "abacadaeaf";
    //string encoded = huffman.encode(input1);
    //cout << "Encoded: " << encoded << endl;

    // Call the compressData function
    //vector<pair<int, vector<char>>> compressedData = rlEncoding.compressData(input);
/*
    // Call the decompressData function
    vector<char> decompressedData = rlEncoding.decompressData();

    // Call the getCompressedData function
    vector<pair<int, vector<char>>> compressedDataResult = rlEncoding.getCompressedData();

    // Call the getDecompressedData function
    vector<char> decompressedDataResult = rlEncoding.getDecompressedData();

    // Call the getCompressedString function
    string compressedString = rlEncoding.getCompressedString();

    double compressionRatioRLE = rlEncoding.compressionRatio();
    cout << "Compression ratio:" << compressionRatioRLE << endl;

    //rlEncoding.printCompressedData();


    // Print the results
    cout << "Compressed Data: ";
    for (const auto& pair : compressedDataResult) {
        cout << pair.first << "," << pair.second << endl;
        //cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;*/
/*
    cout << "Decompressed Data: ";
    for (const auto& value : decompressedDataResult) {
        cout << value << " ";
    }
    cout << endl;

    cout << "Compressed String: " << compressedString << endl;

    */
    
    /*// Multithreading
    vector<char> inputData = {'a', 'a', 'b', 'c', 'c', 'c', 'd', 'e', 'e', 'e', 'e'};
    
    MultiThreadedCompression<vector<char>> multiThreadedCompression(inputData);
    multiThreadedCompression.compressInBlocks();

    auto compressedData = multiThreadedCompression.getCompressedData();

    // Print or process the compressed data as needed
    for (const auto& pair : compressedData) {
        cout << "(" << pair.first << ", '" << pair.second[0] << "')" << endl;
    }
    */

    return 0;
}

