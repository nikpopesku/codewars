#include "../cw_compat.hpp"
#include <vector>

using namespace std;

char findMissingLetter(const vector<char>& chars)
{
    int counter = 0;
    for (char i = chars[0]; i <= chars[chars.size() - 1]; ++i, ++counter)
    {
        if (chars[counter] != i)
        {
            return i;
        }
    }

    if (tolower(chars[chars.size() - 1]) != 'z')
    {
        return static_cast<char>(chars[chars.size() - 1] + 1);
    }

    return static_cast<char>(chars[0] - 1);
}


Describe(sample_test_cases)
{
    It(should_pass_sample_fixed_tests)
    {
        Assert::That(findMissingLetter({'a', 'b', 'c', 'd', 'f'}), Equals('e'), ExtraMessage("Incorrect output for input = ['a', 'b', 'c', 'd', 'f']"));
        Assert::That(findMissingLetter({'O', 'Q', 'R', 'S'}), Equals('P'), ExtraMessage("Incorrect output for input = ['O', 'Q', 'R', 'S']"));
    }
}
