#include <string>
#include <set>

using namespace std;

bool is_pangram(const std::string& s)
{
    set<char> ss;

    for (char i = 'a'; i <= 'z'; ++i)
    {
        ss.insert(i);
    }

    for (const auto& c : s)
    {
        if (ss.find(tolower(c)) != ss.end())
        {
            ss.erase(tolower(c));
        }
    }

    return ss.empty();
}


#include "cw_compat.hpp"

Describe(sample_tests)
{
    It(should_return_true)
    {
        Assert::That(is_pangram("The quick, brown fox jumps over the lazy dog!"), Equals(true));
    };

    It(should_return_false)
    {
        Assert::That(is_pangram("1bcdefghijklmnopqrstuvwxyz"), Equals(false));
    };
};
