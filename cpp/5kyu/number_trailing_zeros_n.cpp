#include "../cw_compat.hpp"
#include <cmath>

using namespace std;

long zeros(const long n)
{
    long response = 0;

    const double lg = log(n) / log(2);

    for (int i = 1; i < lg; ++i)
    {
        response += floor(n / pow(5, i));
    }

    return response;
}

Describe(Sample_Tests)
{
    It(Tests)
    {
        Assert::That(zeros(0), Equals(0));
        Assert::That(zeros(6), Equals(1));
        Assert::That(zeros(30), Equals(7));
        Assert::That(zeros(100), Equals(24));
        Assert::That(zeros(1000), Equals(249));
        Assert::That(zeros(100000), Equals(24999));
        Assert::That(zeros(1000000000), Equals(249999998));
    }
};
