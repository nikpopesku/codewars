#include "../cw_compat.hpp"

using namespace std;

long nextBigger(long n) {
    return n;
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