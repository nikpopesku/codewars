#include "../cw_compat.hpp"
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

class SumSquaredDivisors {
public:
    static vector<pair<long long, long long> > listSquared(const long long m, const long long n) {
        vector<pair<long long, long long> > response;

        for (long long i = m; i < n; ++i) {
            vector<long long> divisors = {1};

            if (i > 1) {
                divisors.push_back(i);
            }

            long long divisor = 2;
            while (divisor * divisor <= i) {
                if (i % divisor == 0) {
                    divisors.push_back(divisor);
                    if (i / divisor != divisor) {
                        divisors.push_back(i / divisor);
                    }
                }
                ++divisor;
            }

            long long value = 0;

            for (const auto &d: divisors) {
                value += d * d;
            }

            if (const double sr = sqrt(value); ceil(sr) == floor(sr)) {
                response.push_back({i, value});
            }
        }

        return response;
    }
};

using Result = vector<pair<long long, long long> >;

void testequal(const Result &ans, const Result &sol) {
    Assert::That(ans, Equals(sol));
}

void dotest(long long m, long long n, const Result &expected) {
    testequal(SumSquaredDivisors::listSquared(m, n), expected);
}

Describe(listSquared_Tests) {
    It(Fixed_Tests) {
        dotest(1, 250, {{1, 1}, {42, 2500}, {246, 84100}});
        dotest(42, 250, {{42, 2500}, {246, 84100}});
        dotest(250, 500, {{287, 84100}});
        dotest(300, 600, {});
    }
};
