#include <string>
#include <unordered_map>

using namespace std; 

size_t duplicateCount(const string& in)
{
    unordered_map<char, int> s;
    for (const auto& c : in)
    {
        ++s[tolower(c)];
    }

    int response = 0;

    for (auto& [fst, snd] : s)
    {
        if (snd >= 2)
        {
            ++response;
        }
    }


    return static_cast<size_t>(response);
}

#include "cw_compat.hpp"

Describe(sample_test_cases)
{
    It(should_pass_basic_fixed_tests)
    {
        Assert::That(duplicateCount("asdfghjkl54"), Equals(0),
                     ExtraMessage(R"(Incorrect output for input = "asdfghjkl54")"));
        Assert::That(duplicateCount("abcdeaa"), Equals(1), ExtraMessage(R"(Incorrect output for input = "abcdeaa")"));
        Assert::That(duplicateCount("93917949902"), Equals(1),
                     ExtraMessage(R"(Incorrect output for input = "93917949902")"));
        Assert::That(duplicateCount("hhhhhhHHhhHHHHhhhhhHhH"), Equals(1),
                     ExtraMessage(R"(Incorrect output for input = "hhhhhhHHhhHHHHhhhhhHhH")"));
        Assert::That(duplicateCount("asdfghjkl55"), Equals(1),
                     ExtraMessage(R"(Incorrect output for input = "asdfghjkl55")"));
        Assert::That(duplicateCount("aabbcde"), Equals(2), ExtraMessage(R"(Incorrect output for input = "aabbcde")"));
        Assert::That(duplicateCount("aabBcde"), Equals(2), ExtraMessage(R"(Incorrect output for input = "aabBcde")"));
        Assert::That(duplicateCount("abcdeaB"), Equals(2), ExtraMessage(R"(Incorrect output for input = "abcdeaB")"));
        Assert::That(duplicateCount("0"), Equals(0), ExtraMessage(R"(Incorrect output for input = "0")"));
        Assert::That(duplicateCount("000000000112"), Equals(2),
                     ExtraMessage(R"(Incorrect output for input = "000000000112")"));
        Assert::That(duplicateCount("Indivisibility"), Equals(1),
                     ExtraMessage(R"(Incorrect output for input = "Indivisibility")"));
        Assert::That(duplicateCount("Indivisibilities"), Equals(2),
                     ExtraMessage(R"(Incorrect output for input = "Indivisibilities")"));
    }
};
