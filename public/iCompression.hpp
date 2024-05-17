#ifndef ICOMPRESSION_HPP
#define ICOMPRESSION_HPP

#include <vector>
#include <string>
#include <complex>

struct iCompression {
    virtual ~iCompression() = default;

    virtual std::vector<std::pair<int, std::complex<float>>> compressData(std::vector<std::complex<float>> data) = 0;

    virtual std::vector<std::pair<int, std::complex<float>>> getCompressedData() const = 0;

    virtual void printCompressedData() const = 0;

    virtual void setAlgorithmParameters() = 0;

    virtual std::vector<std::string> getAlgorithmParameters() const = 0;
};

#endif // ICOMPRESSION_HPP
