#include "../cw_compat.hpp"

using namespace std;

using ull = unsigned long long;

ull exp_sum(const unsigned int n)
{
    vector dp(n + 1, vector<ull>(n + 1, 0));

    for (unsigned int col = 1; col <= n; ++col)
    {
        dp[0][col] = 1;
    }

    for (unsigned int row = 1; row <= n; ++row)
    {
        dp[row][0] = 0;
    }

    for (unsigned int row = 1; row <= n; ++row)
    {
        for (unsigned int col = 1; col <= n; ++col)
        {
            dp[row][col] = dp[row][col - 1] + dp[row - 1][col];
        }
    }

    return dp[n][n];
}

Describe(explosive_sum_2d_tests)
{
    It(Basic_Tests)
    {
        Assert::That(exp_sum(1), Equals(1));
        Assert::That(exp_sum(2), Equals(2));
        Assert::That(exp_sum(3), Equals(3));
        Assert::That(exp_sum(4), Equals(5));
        Assert::That(exp_sum(5), Equals(7));
        Assert::That(exp_sum(10), Equals(42));
    }

    It(Explosive_Tests)
    {
        Assert::That(exp_sum(50), Equals(204226));
        Assert::That(exp_sum(80), Equals(15796476));
        Assert::That(exp_sum(100), Equals(190569292));
    }

    It(Edge_Cases)
    {
        Assert::That(exp_sum(0), Equals(1));
    }

    It(Verification_Tests)
    {
        Assert::That(exp_sum(6), Equals(11)); // Known partition number
        Assert::That(exp_sum(7), Equals(15)); // Known partition number
        Assert::That(exp_sum(8), Equals(22)); // Known partition number
        Assert::That(exp_sum(9), Equals(30)); // Known partition number
    }
};
