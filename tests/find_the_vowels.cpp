#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <string>

// Declaration of the function under test (implemented in kata/find_the_vowels.cpp)
std::vector<int> vowelIndices(const std::string& word);

TEST_CASE("vowelIndices simple tests") {
    std::vector res{2, 4};
    REQUIRE(vowelIndices("super") == res);
}

TEST_CASE("vowelIndices simple test1") {
    std::vector res{1, 3, 6};
    REQUIRE(vowelIndices("orAnge") == res);
}