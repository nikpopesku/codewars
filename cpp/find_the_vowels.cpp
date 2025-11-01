#include "cw_compat.hpp"
#include <vector>
#include <string>

std::vector<int> vowelIndices(const std::string& word)
{
    std::vector<int> res;
    char charArray[] = {'a', 'e', 'i', 'o', 'u', 'y'};

    for (int i = 0; i < static_cast<int>(word.size()); ++i)
    {
        for (const auto& c : charArray)
        {
            if (tolower(word[i]) == c)
            {
                res.push_back(i + 1);
            }
        }
    }

    return res;
}

Describe(vowelIndicesTest)
{
    It(SimpleTests)
    {
        const std::vector res { 2, 4 };
        Assert::That(vowelIndices("super"), Equals(res));
    }
};