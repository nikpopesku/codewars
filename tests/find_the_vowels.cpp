#include <vector>
#include <string>

std::vector<int> vowelIndices(const std::string& word);
#include "cw_compat.hpp"

Describe(vowelIndicesTest)
{
    It(SimpleTests)
    {
        std::vector<int> res { 2, 4 };
        Assert::That(vowelIndices("super"), Equals(res));
    }
};