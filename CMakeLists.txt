cmake_minimum_required(VERSION 3.10)
project(DataCompressionProject)

# Add the source files
file(GLOB SOURCE_FILES source/*.cpp)


# Set the include directories
include_directories(public)

# Add an executable target
add_executable(DataCompressionProject ${SOURCE_FILES})

# Set C++ standard (Change as needed)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Additional compiler flags if needed
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -v")

# Set the output directory for the executable
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)