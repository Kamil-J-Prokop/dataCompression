#include "ICompression.hpp"
#include "IDecompression.hpp"
#include <sstream>
#include <vector>
#include <string>

using namespace std;

template <typename Container>
class RunLengthEncodingCompression : public ICompression<Container>, public IDecompression<Container> {


public:
    ~RunLengthEncodingCompression() override = default;

    vector<pair<int, Container>> compressData(Container data) override {
    mCompressedData.clear();
    mCompressedString.clear();

    auto it = data.begin();
    while (it != data.end()) {
        int count = 1;
        auto next = std::next(it);
        while (next != data.end() && *it == *next) {
            ++count;
            ++next;
        }

        mCompressedData.push_back(make_pair(count, Container(*it)));
        mCompressedString += to_string(count) + *it;

        it = next;
        }

    return mCompressedData;
    }

    /*vector<pair<int, Container>> compressData(Container data) override {
        mCompressedData.clear();
        mCompressedString.clear();

        for (size_t i = 0; i < data.size(); i++) {
            int count = 1;

            while (i + 1 < data.size() && data[i] == data[i + 1]) {
                i++;
                count++;
            }

            mCompressedData.push_back(make_pair(count, data[i]));
            mCompressedString += to_string(count) + data[i];
        }

        return mCompressedData;
    }*/

    Container decompressData() override {
        mDecompressedData.clear();

        for (auto &pair : mCompressedData) {
            int count = pair.first;
            Container value = pair.second;

            for (int i = 0; i < count; i++) {
                mDecompressedData.insert(mDecompressedData.end(), value.begin(), value.end());;
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

    vector<pair<int, Container>> getCompressedData() const override {
        return mCompressedData;
    }

    Container getDecompressedData() const override {
        return mDecompressedData;
    }

    string getCompressedString() const override {
        return mCompressedString;
    }


private:
    vector<pair<int, Container>> mCompressedData;
    Container mDecompressedData;
    string mCompressedString;

};
