#include "../cw_compat.hpp"

using namespace std;


long nextBigger(const long n)
{
    string s = to_string(n);
    const int l = s.length();

    int i = l - 2;
    while (i >= 0 && s[i] >= s[i + 1])
    {
        --i;
    }

    if (i < 0)
    {
        return -1;
    }

    int j = l - 1;
    while (s[j] <= s[i])
    {
        --j;
    }

    swap(s[i], s[j]);

    reverse(s.begin() + i + 1, s.end());

    return stoll(s);
}

Describe(NextBiggerNumber)
{
    It(BasicTests)
    {
        Assert::That(nextBigger(531), Equals(-1));
        Assert::That(nextBigger(9), Equals(-1));
        Assert::That(nextBigger(111), Equals(-1));
        Assert::That(nextBigger(12), Equals(21));
        Assert::That(nextBigger(513), Equals(531));
        Assert::That(nextBigger(2017), Equals(2071));
        Assert::That(nextBigger(414), Equals(441));
        Assert::That(nextBigger(144), Equals(414));
        Assert::That(nextBigger(10990), Equals(19009));
    }
};
