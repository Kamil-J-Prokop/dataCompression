#ifndef ICOMPRESSION_HPP
#define ICOMPRESSION_HPP

#include <vector>
#include <string>



struct iCompression //interface compression
{
    //typename std::vector <std::pair<int, Container>> encodedDataType;

    virtual ~iCompression() = default; // zawsze klasa bazowa musi miec destruktor wirtualny, czasami moze miec jakas implementacje i nie byc defaultowy
            
    virtual std::vector<std::pair<int, int>> compressData(std::vector<int> data) = 0;

    virtual std::vector<std::pair<int, int>> getCompressedData() const = 0;

    virtual void printCompressedData() const = 0;

    virtual void setAlgorithmParameters() = 0;

    virtual std::vector<std::string> getAlgorithmParameters() const = 0;
    //virtual std::string getAlgorithmName() const = 0; //jak dostarczyc implementacje
     
};

#endif // ICOMPRESSION_HPP

//piszac klase bazowa - destruktor klasy bazowej 