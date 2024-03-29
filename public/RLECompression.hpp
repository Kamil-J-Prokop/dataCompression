#ifndef RUN_LENGTH_ENCODING_HPP
#define RUN_LENGTH_ENCODING_HPP

#include "iCompression.hpp"
#include <vector>
#include <utility>

class RLECompression : public iCompression {

public:
    std::vector<std::pair<int, int>> compressData(std::vector<int> data) override;

    std::vector<std::pair<int, int>> getCompressedData() const override;

    void printCompressedData() const;

    void setAlgorithmParameters() override;

    std::vector<std::string> getAlgorithmParameters() const override;

private:
    std::vector<std::pair<int, int>> compressedData;

    std::vector<std::string> algoParameters;
};

#endif // RUN_LENGTH_ENCODING_HPP
