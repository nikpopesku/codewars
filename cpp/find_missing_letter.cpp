#include "cw_compat.hpp"
#include <vector>

char findMissingLetter(const std::vector<char>& chars)
{
    // TODO: Find the missing char in the consecutive letter sequence and return it.
    return ' ';
}


Describe(sample_test_cases)
{
    It(should_pass_sample_fixed_tests)
    {
        Assert::That(findMissingLetter({'a', 'b', 'c', 'd', 'f'}), Equals('e'), ExtraMessage("Incorrect output for input = ['a', 'b', 'c', 'd', 'f']"));
        Assert::That(findMissingLetter({'O', 'Q', 'R', 'S'}), Equals('P'), ExtraMessage("Incorrect output for input = ['O', 'Q', 'R', 'S']"));
    }
}
