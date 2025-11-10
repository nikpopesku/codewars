#include <unordered_set>

#include "../cw_compat.hpp"

using namespace std;

void backtrack(const vector<long>& v, const long value, long& n, long& mx, unordered_set<long> ss)
{
    if (ss.size() == v.size())
    {
        if (value > n && (mx == -1 || value < mx))
        {
            mx = value;
        }

        return;
    }

    for (long i = 0; i < static_cast<long>(v.size()); ++i)
    {
        if (ss.count(i) == 0)
        {
            ss.insert(i);
            backtrack(v, value * 10 + v[i], n, mx, ss);
            ss.erase(i);
        }

    }
}

long nextBigger(long n)
{
    const long temp = n;
    vector<long> v;

    n = temp;
    while (n)
    {
        v.push_back(n % 10);
        n /= 10;
    }

    long mx = -1;

    n = temp;
    backtrack(v, 0, n, mx, {});

    return mx;
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
