#include <iostream>
#include <vector>
#include <string>
#include <list>

#include "../Public/ICompression.hpp"
#include "../Public/IDecompression.hpp"
#include "../Public/RunLengthEncodingCompression.hpp"

using namespace std;


int main()
{
    
    vector<int> input = {1, 4, 3, 5, 3, 3, 3, 3 , 3, 3, 3, 2, 1, 5, 4, 3, 5, 6, 7, 7, 7, 7, 7, 1, 4, 3, 5, 3, 3, 3, 3, 3, 3, 3, 2, 1, 5, 4, 3, 5, 6, 7, 7, 7, 7, 7,7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
    //DataHandler obj1l(input);
    RunLengthEncodingCompression<vector<int>> obj1;
    obj1.compressData(input);
    obj1.printCompressedData();
    return 0;
}

