#include "../cw_compat.hpp"
using ull = unsigned long long;

ull exp_sum(unsigned int n) {
    return 0;
}

Describe(Sample_Tests)
{
    It(Tests)
    {
        Assert::That(exp_sum(1), Equals(1));
        Assert::That(exp_sum(2), Equals(2));
        Assert::That(exp_sum(3), Equals(3));
        Assert::That(exp_sum(4), Equals(5));
        Assert::That(exp_sum(5), Equals(7));
        Assert::That(exp_sum(10), Equals(42));
    }
};