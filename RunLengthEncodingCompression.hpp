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
    /*virtual*/ /*~RunLengthEncodingCompression() override = default; // dostarczenie implementacji funkcji ktora byla wirtualna, jak funkcja bazowa nie byla wirtualna to kompilator wywali blad

    //ICompression<Container>::encodedDataType compressData(Container data) override; // zastanowic sie jak to zrobic

    vector<pair<int, Container>>  compressData(Container data) override;

    Container decompressData() override;

    int numberOfFirstElements() const;

    vector<pair<int, Container>> getCompressedData() const override;

    Container getDecompressedData() const override;

    string getCompressedString() const override;*/

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

        mCompressedData.push_back(make_pair(count, Container(*it)));
        mCompressedString += to_string(count) + *it;

        it = nextSign;
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

    /*template <typename T, typename T2>
    static void printPair(const std::pair<int, T2>& pair) {
    std::cout << "(" << pair.first << ", ";

    // Print the second element based on its type
    if constexpr (std::is_same_v<T2, int>) {
        std::cout << pair.second;
    } else if constexpr (std::is_same_v<T2, double>) {
        std::cout << pair.second;
    } else if constexpr (std::is_same_v<T2, char>) {
        std::cout << "'" << pair.second << "'";
    } else if constexpr (std::is_same_v<T2, std::vector<int>>) {
        // Assuming the second element is a vector of integers
        std::cout << "vector<int> { ";
        for (const auto& elem : pair.second) {
            std::cout << elem << " ";
        }
        std::cout << "}";
    } else if constexpr (std::is_same_v<T2, std::vector<double>>) {
        // Assuming the second element is a vector of doubles
        std::cout << "vector<double> { ";
        for (const auto& elem : pair.second) {
            std::cout << elem << " ";
        }
        std::cout << "}";
    }
    // Add more conditions for other types as needed

    std::cout << ")" << std::endl;
    }*/

    template <typename T, typename T2>
    void printCompressedData()
    {
        for (const auto& pair : mCompressedData)
        {
        std::cout << "(" << pair.first << ", ";

        // Print the second element based on its type
        if constexpr (std::is_same_v<T2, int>) 
        {
            std::cout << pair.second;
        } 
        else if constexpr (std::is_same_v<T2, double>) 
        {
            std::cout << pair.second;
        } 
        else if constexpr (std::is_same_v<T2, char>) 
        {
            std::cout << "'" << pair.second << "'";
        } 
        else if constexpr (std::is_same_v<T2, std::vector<int>>) 
        {
        // Assuming the second element is a vector of integers
            std::cout << "vector<int> { ";
            for (const auto& elem : pair.second) 
            {
                std::cout << elem << " ";
            }
            std::cout << "}";
        }
        else if constexpr (std::is_same_v<T2, std::vector<double>>) 
        {
        // Assuming the second element is a vector of doubles
            std::cout << "vector<double> { ";
            for (const auto& elem : pair.second) {
                std::cout << elem << " ";
            }
            std::cout << "}";
        }
    // Add more conditions for other types as needed

    std::cout << ")" << std::endl;
    };
        
    }

private:  //wszystkie membery na koncu klasy, m na poczatku znaczy member
    vector<pair<int, Container>> mCompressedData;  //uproscic nazwe tego typu - zrobic alias
    Container mDecompressedData;
    string mCompressedString;

    
};

#endif // RUNLENGTHENCODINGCOMPRESSION_HPP;