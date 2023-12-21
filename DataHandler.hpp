#include <vector>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
class DataHandler {
public:
   DataHandler(T input) {
       mData = input;
   }
   vector<char> toCharVector() {
       vector<char> result;
       if constexpr (is_same<T, string>::value) {
           for (char c : mData) {
               result.push_back(c);
           } //upewnic sie czy to co jest w else if jest rowniez constexprowe 
       } else if constexpr (is_same<T, vector<string>>::value) {
           for (string s : mData) {
               for (char c : s) {
                  result.push_back(c);
               }
           }
       }
       return result;
   }
   vector<int> toIntVector() {
       vector<int> result;
       if constexpr (is_same<T, int>::value) {
           result.push_back(mData);
       } else if constexpr (is_same<T, vector<int>>::value) {
           result = mData;
       } else if constexpr (is_same<T, vector<double>>::value) {
           for (double d : mData) {
               result.push_back(static_cast<int>(d));
           }
       }
       return result;
   }
   vector<double> toDoubleVector() {
       vector<double> result;
       if constexpr (is_same<T, double>::value) {
           result.push_back(mData);
       } else if constexpr (is_same<T, vector<double>>::value) {
           result = mData;
       }
       return result;
   }
   T mData;
};
