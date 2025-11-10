#include "../cw_compat.hpp"

#include <unordered_set>

using namespace std;


long nextBigger(long n)
{
    if (n < 10)
    {
        return -1;
    }

    long last_digit = -1;
    bool is_biggest = true;

    while (n > 0)
    {
        const long current_digit = n % 10;

        if (current_digit < last_digit)
        {
            is_biggest = false;
            break;
        }

        n = n / 10;
        last_digit = current_digit;
    }

    if (is_biggest)
    {
        return -1;
    }
}

Describe(NextBiggerNumber)
{
    It(BasicTests)
    {
        Assert::That(nextBigger(531), Equals(-1));
        Assert::That(nextBigger(9), Equals(-1));
        Assert::That(nextBigger(111), Equals(-1));
        // Assert::That(nextBigger(12), Equals(21));
        // Assert::That(nextBigger(513), Equals(531));
        // Assert::That(nextBigger(2017), Equals(2071));
        // Assert::That(nextBigger(414), Equals(441));
        // Assert::That(nextBigger(144), Equals(414));
        // Assert::That(nextBigger(10990), Equals(19009));
    }
};
