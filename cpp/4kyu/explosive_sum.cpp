#include "../cw_compat.hpp"

using namespace std;

using ull = unsigned long long;

ull exp_sum(const unsigned int n) {
    if (n == 0) {
        return 1;
    }

    vector<ull> dp(n + 1, 0);
    dp[0] = 1;

    for (unsigned int k = 1; k <= n; ++k) {
        for (unsigned int i = k; i <= n; ++i) {
            dp[i] += dp[i - k];
        }
    }

    return dp[n];
}

Describe(Sample_Tests) {
    It(Tests) {
        Assert::That(exp_sum(1), Equals(1));
        Assert::That(exp_sum(2), Equals(2));
        Assert::That(exp_sum(3), Equals(3));
        Assert::That(exp_sum(4), Equals(5));
        Assert::That(exp_sum(5), Equals(7));
        Assert::That(exp_sum(10), Equals(42));
    }
};
