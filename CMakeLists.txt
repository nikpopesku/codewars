cmake_minimum_required(VERSION 3.16)
project(codewars CXX)

find_package(Catch2 3 REQUIRED)

# Build the code under test as a library with all kata sources
add_library(kata STATIC
    kata/quarter_of_the_year.cpp
    kata/find_the_vowels.cpp
)

# Test executable containing all test files
add_executable(YourTestRunner
    tests/quarter_of_the_year.cpp
    tests/find_the_vowels.cpp
)

# Link Catch2 main and your library
target_link_libraries(YourTestRunner PRIVATE kata Catch2::Catch2WithMain)

# Enable test discovery
include(CTest)
include(Catch)
catch_discover_tests(YourTestRunner)