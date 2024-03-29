#ifndef IDECOMPRESSION_HPP
#define IDECOMPRESSION_HPP

#include <vector>
#include <string>

using namespace std;

template <typename Container>
struct IDecompression //interface compression
{

    virtual ~IDecompression() = default; // zawsze klasa bazowa musi miec destruktor wirtualny, czasami moze miec jakas implementacje i nie byc defaultowy

    virtual Container decompressData() = 0;

    virtual Container getDecompressedData() const = 0;

    //virtual std::string getAlgorithmName() const = 0;


};

#endif // IDECOMPRESSION_HPP;

//piszac klase bazowa - destruktor klasy bazowej 