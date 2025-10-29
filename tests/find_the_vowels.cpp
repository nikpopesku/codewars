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

TEST_CASE("vowelIndices simple test2") {
    std::vector res{5, 9, 11, 12, 18, 19, 24, 25, 28, 34, 35, 36, 37, 39, 53, 63};
    REQUIRE(vowelIndices("RNmfYmXSegaejlSXXiObWkRaafbeVXQlVOiUakOkQlkkXdScmTWhibWdhkNTkbacbfbjlbcQ") == res);
}