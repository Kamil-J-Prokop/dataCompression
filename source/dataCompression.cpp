#include <iostream>
#include <fstream>
#include "RLECompression.hpp"
#include "Huffman.hpp"
#include <vector>
#include <algorithm>
#include <math.h>
#include <fcwt.h>

int main(int argc, char * argv[]) {
    std::vector<std::complex<float>> input = {
        {1.0f, 0.0f},
        {2.0f, 0.0f}, {2.0f, 0.0f},
        {3.0f, 0.0f}, {3.0f, 0.0f}, {3.0f, 0.0f},
        {4.0f, 0.0f}, {4.0f, 0.0f}, {4.0f, 0.0f}, {4.0f, 0.0f},
        {5.0f, 0.0f}, {5.0f, 0.0f}, {5.0f, 0.0f}, {5.0f, 0.0f}, {5.0f, 0.0f} 
    };

    // Create an instance of RLECompression
    RLECompression rle;

    // Call compressData method with complex<float> input
    std::vector<std::pair<int, std::complex<float>>> compressed = rle.compressData(input);

    // Print compressed data
    rle.printCompressedData();

    // Call getCompressedData method to retrieve compressed data
    std::vector<std::pair<int, std::complex<float>>> pairs1 = rle.getCompressedData();

        // Sample data for Huffman compression
 std::vector<std::pair<int, std::complex<float>>> pairs = {
        {3, std::complex<float>(1.0, 2.0)},
        {5, std::complex<float>(2.0, 3.0)},
        {2, std::complex<float>(3.0, 4.0)},
        {4, std::complex<float>(4.0, 5.0)}
    };

    // Build the Huffman tree
    std::shared_ptr<Node> root = buildHuffmanTree(pairs);

    // Initialize an unordered_map to store the Huffman codes
    std::unordered_map<std::pair<int, std::complex<float>>, std::string, PairHash, PairEqual> codes;

    // Generate Huffman codes
    generateHuffmanCodes(root, codes);

    // Print the Huffman codes
    for (const auto& code : codes) {
        std::cout << "Complex: (" << code.first.first << ", " << code.first.second << ") -> Code: " << code.second << std::endl;
    }

    int n = 10; //signal length
    const int fs = 10; //sampling frequency
    float twopi = 2.0*3.1415;
    
    //3000 frequencies spread logartihmically between 1 and 32 Hz
    const float f0 = 1;
    const float f1 = 32;
    const int fn = 30;

    //Define number of threads for multithreaded use
    const int nthreads = 8; // arm, stm32

    //input: n real numbers
    std::vector<float> sig(n);
    
    //output: n x scales
    std::vector<complex<float>> tfm(n*fn);
    
    //initialize with 1 Hz cosine wave
    for(auto& el : sig) {
        el = cos(twopi*((float)(&el - &sig[0])/(float)fs));
    }
    
    //Create a wavelet object
    Wavelet *wavelet;
    
    //Initialize a Morlet wavelet having sigma=2.0;
    Morlet morl(2.0f);
    wavelet = &morl;

    //Create the continuous wavelet transform object
    //constructor(wavelet, nthreads, optplan)
    //
    //Arguments
    //wavelet   - pointer to wavelet object
    //nthreads  - number of threads to use
    //optplan   - use FFTW optimization plans if true
    //normalization - take extra time to normalize time-frequency matrix
    FCWT fcwt(wavelet, nthreads, true, false);

    //Generate frequencies
    //constructor(wavelet, dist, fs, f0, f1, fn)
    //
    //Arguments
    //wavelet   - pointer to wavelet object
    //dist      - FCWT_LOGSCALES | FCWT_LINFREQS for logarithmic or linear distribution frequency range
    //fs        - sample frequency
    //f0        - beginning of frequency range
    //f1        - end of frequency range
    //fn        - number of wavelets to generate across frequency range
    Scales scs(wavelet, FCWT_LINFREQS, fs, f0, f1, fn);

    //Perform a CWT
    //cwt(input, length, output, scales)
    //
    //Arguments:
    //input     - floating pointer to input array
    //length    - integer signal length
    //output    - floating pointer to output array
    //scales    - pointer to scales object
    fcwt.cwt(&sig[0], n, &tfm[0], &scs);


/*
    for (const auto& point : tfm) {
        std::cout << "(" << point.real() << ", " << point.imag() << ")" << std::endl;
    }
*/
    auto print = [](const auto& point) { std::cout << "(" << point.real() << ", " << point.imag() << ")" << std::endl; };
 

    std::for_each(tfm.cbegin(), tfm.cend(), print);
    
    /*
    std::ofstream outputFile("output.txt"); // create a new output file or overwrite an existing one

    if (outputFile.is_open()) { // check if the file was opened successfully
    outputFile << fcwt.cwt(&sig[0], n, &tfm[0], &scs); // write data to the file
    outputFile.close(); // close the file when done
    std::cout << "Data was written to output.txt\n";
    }
    else {
    std::cerr << "Error opening file\n";
    }
    */

    return 0;
}