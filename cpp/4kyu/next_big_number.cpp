#include <unordered_set>

#include "../cw_compat.hpp"

using namespace std;

long nextBigger(long n)
{
    if (n < 10)
    {
        return -1L;
    }

    bool is_biggest = true;
    int last_digit = -1;
    unordered_set<int> s;

    while (n > 0)
    {
        int current_digit = n % 10;
        s.insert(current_digit);

        if (last_digit != -1)
        {
            if (current_digit < last_digit)
            {
                is_biggest = false;
                break;
            }

            if (current_digit >= last_digit)
            {
                last_digit = current_digit;
            }
        }

        n = n / 10;
        last_digit = current_digit;
    }

    if (is_biggest || s.size() == 1)
    {
        return -1;
    }
}

Describe(NextBiggerNumber)
{
    It(BasicTests)
    {
        Assert::That(nextBigger(12), Equals(21));
        Assert::That(nextBigger(513), Equals(531));
        Assert::That(nextBigger(2017), Equals(2071));
        Assert::That(nextBigger(414), Equals(441));
        Assert::That(nextBigger(144), Equals(414));
        Assert::That(nextBigger(10990), Equals(19009));
    }
};
