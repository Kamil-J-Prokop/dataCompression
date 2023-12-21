#ifndef ICOMPRESSION_HPP
#define ICOMPRESSION_HPP

#include <vector>
#include <string>

using namespace std;

template <typename Container>
struct ICompression //interface compression
{
    //typename std::vector <std::pair<int, Container>> encodedDataType;

    virtual ~ICompression() = default; // zawsze klasa bazowa musi miec destruktor wirtualny, czasami moze miec jakas implementacje i nie byc defaultowy
            
    virtual vector<pair<int, Container>> compressData(Container data) = 0;

    virtual vector<pair<int, Container>> getCompressedData() const = 0;

    virtual string getCompressedString() const = 0;

    virtual double compressionRatio() = 0;

    //virtual std::string getAlgorithmName() const = 0; //jak dostarczyc implementacje
     
};

#endif // ICOMPRESSION_HPP;

//piszac klase bazowa - destruktor klasy bazowej 