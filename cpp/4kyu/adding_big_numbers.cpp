#include "../cw_compat.hpp"

using namespace std;

#include <string>

string add(const string& a, const string& b) {
    return "";
}

Describe(Sample_Tests)
{
    It(Tests)
    {
        Assert::That(add("123", "456"), Equals("579"));
        Assert::That(add("0", "0"), Equals("0"));
        Assert::That(add("99", "2"), Equals("101"));
        Assert::That(add("10", "35679"), Equals("35689"));
        Assert::That(add("", "5"), Equals("5"));
        Assert::That(add("192", ""), Equals("192"));
        Assert::That(add("9999", "1111"), Equals("11110"));
    }
};