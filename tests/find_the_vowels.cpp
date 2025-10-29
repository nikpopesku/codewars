#include <catch2/catch_test_macros.hpp>

// Declaration to use the function implemented in quarter_of_the_year.cpp
int quarter_of(const int month);

Describe(vowelIndicesTest)
{
    It(SimpleTests)
    {
        std::vector<int> res { 2, 4 };
        Assert::That(vowelIndices("super"), Equals(res));
    }
};