cmake_minimum_required(VERSION 3.16)
project(codewars CXX)

find_package(Catch2 3 REQUIRED)

# Build the code under test as a library (or you can list the .cpp in the test executable directly)
add_library(quarter STATIC kata/quarter_of_the_year.cpp)

# Test executable
add_executable(YourTestRunner tests/quarter_of_the_year.cpp)

# Link Catch2 main and your library
target_link_libraries(YourTestRunner PRIVATE quarter Catch2::Catch2WithMain)

# Enable test discovery
include(CTest)
include(Catch)
catch_discover_tests(YourTestRunner)