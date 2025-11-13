#include "../cw_compat.hpp"
#include <string>

using namespace std;

int knight(string start, string finish) {
    return 0;
}

Describe(Sample_Tests)
{
    It(Tests)
    {
        Assert::That(knight("a1", "c1"), Equals(2));
        Assert::That(knight("a1", "f1"), Equals(3));
        Assert::That(knight("a1", "f3"), Equals(3));
        Assert::That(knight("a1", "f4"), Equals(4));
        Assert::That(knight("a1", "f7"), Equals(5));
    }
};