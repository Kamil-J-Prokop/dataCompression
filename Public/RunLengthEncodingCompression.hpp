#ifndef RUNLENGTHENCODINGCOMPRESSION_HPP
#define RUNLENGTHENCODINGCOMPRESSION_HPP

#include "ICompression.hpp"
#include "IDecompression.hpp"
#include <sstream>
#include <vector>
#include <string>

#define PERCENT_CONVERSION 100
//sa dwie szkoly - albo mozna includowac wszystkie biblioteki/komponenty w kazdym scope, albo inkludujuemy tylko raz dany komponent - kiedys byl to plus na wydajnosci kompilacji

using namespace std; // zastanowic sie czy warto includowac, dla pliku h/hpp include jest globalny

template <typename Container>
class RunLengthEncodingCompression : public ICompression<Container>, public IDecompression<Container>
{
public:
    RunLengthEncodingCompression() = default;
    ~RunLengthEncodingCompression() override = default;

    vector<pair<int, Container>> compressData(Container data) override {
    mCompressedData.clear();
    mCompressedString.clear();

    auto it = data.begin();
    while (it != data.end()) {
        int count = 1;
        auto nextSign = std::next(it);
        while (nextSign != data.end() && *it == *nextSign) {
            ++count;
            ++nextSign;
        }

        Container compressedValue;
        compressedValue.push_back(*it); // Push the actual value instead of *it itself

        mCompressedData.push_back(make_pair(count, compressedValue));
        mCompressedString += to_string(count) + to_string(*it);
        it = nextSign;
        }

    return mCompressedData;
    }

    Container decompressData() override {
        mDecompressedData.clear();

        for (auto &pair : mCompressedData) {
            int count = pair.first;
            Container value = pair.second;

            for (int i = 0; i < count; i++) {
                mDecompressedData.insert(mDecompressedData.end(), value.begin(), value.end());
            }
        }

        return mDecompressedData;
    }

    int numberOfFirstElements() const {
        int sum = 0;
            for (const auto& pair : mCompressedData) {
                sum += pair.first;
            }
        return sum;
    }

    double compressionRatio() //unsigned values 
    {
        double compressionRatio;
        compressionRatio = (static_cast<double>(mCompressedData.size())/(static_cast<double>(mDecompressedData.size())))*PERCENT_CONVERSION;
        cout << "Compressed data size:" << mCompressedData.size() << endl;
        cout << "Decompressed data size:" << mDecompressedData.size() << endl;
        return compressionRatio;
    }

    inline vector<pair<int, Container>> getCompressedData() const override {
        return mCompressedData;
    }

    inline Container getDecompressedData() const override {
        return mDecompressedData;
    }

    inline string getCompressedString() const override {
        return mCompressedString;
    }

    void printCompressedData() const {
    for (const auto& pair : mCompressedData) {
        cout << "(" << pair.first << ", ";
        for (const auto& element : pair.second) {
            cout << element;
        }
        cout << ")" << endl;
    }
    }

private:  //wszystkie membery na koncu klasy, m na poczatku znaczy member
    vector<pair<int, Container>> mCompressedData;  //uproscic nazwe tego typu - zrobic alias
    Container mDecompressedData;
    string mCompressedString;

    
};

#endif // RUNLENGTHENCODINGCOMPRESSION_HPP;