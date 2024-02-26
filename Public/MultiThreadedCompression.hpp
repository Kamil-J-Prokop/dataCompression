#ifndef MULTITHREADEDCOMPRESSION_HPP
#define MULTITHREADEDCOMPRESSION_HPP

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <future>
#include "RunLengthEncodingCompression.hpp"

using namespace std;

template <typename Container>
class MultiThreadedCompression {
public:
    MultiThreadedCompression(Container& data) : mData(data) {}

    void compressInBlocks() {
        constexpr size_t block_size = 64; //doczytac constexpr, consteval
        const size_t num_blocks = (mData.size() + block_size - 1) / block_size;

        vector<future<vector<pair<int, Container>>>> futures;
        futures.reserve(num_blocks);

        for (size_t i = 0; i < num_blocks; ++i) {
            const size_t start = i * block_size;
            const size_t end = min((i + 1) * block_size, mData.size());

            // Use async to launch a new thread for compressing each block
            futures.push_back(async([this, start, end]() {
                Container block(mData.begin() + start, mData.begin() + end);
                return mCompression.compressData(block);
            }));
        }

        // Wait for all threads to finish and collect the results
        for (auto& future : futures) {
            auto result = future.get();
            mCompressedData.insert(mCompressedData.end(), result.begin(), result.end());
        }
    }

    vector<pair<int, Container>> getCompressedData() const {
        return mCompressedData;
    }

private:
    Container& mData;
    RunLengthEncodingCompression<Container> mCompression;  // Assuming you have a compression object

    // Mutex to protect access to the shared compressed data
    mutex mMutex;
    vector<pair<int, Container>> mCompressedData;
};

#endif  //MULTITHREADEDCOMPRESSION_HPP;