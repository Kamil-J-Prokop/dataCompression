#ifndef RUN_LENGTH_ENCODING_HPP
#define RUN_LENGTH_ENCODING_HPP

#include "iCompression.hpp"
#include <vector>
#include <complex>
#include <utility>
#include <string>

class RLECompression : public iCompression {

public:
    std::vector<std::pair<int, std::complex<float>>> compressData(std::vector<std::complex<float>> data) override;

    std::vector<std::pair<int, std::complex<float>>> getCompressedData() const override;

    void printCompressedData() const;

    void setAlgorithmParameters() override;

    std::vector<std::string> getAlgorithmParameters() const override;

private:
    std::vector<std::pair<int, std::complex<float>>> compressedData;

    std::vector<std::string> algoParameters;
};

#endif // RUN_LENGTH_ENCODING_HPP
