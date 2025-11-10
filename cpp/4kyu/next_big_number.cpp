#include "../cw_compat.hpp"

#include <unordered_set>

using namespace std;


long nextBigger(const long n)
{
    // 1. Convert to string
    std::string s = std::to_string(n);
    int len = s.length();

    // 2. Find the Pivot
    // Iterate from the second-to-last digit down to the first
    int i = len - 2;
    while (i >= 0 && s[i] >= s[i + 1]) {
        i--;
    }

    // 3. Check for "No Answer"
    // If i < 0, the whole string was in descending order
    if (i < 0) {
        return -1;
    }

    // 4. Find the Swap Digit
    // Iterate from the last digit down to the pivot's position
    int j = len - 1;
    while (s[j] <= s[i]) {
        j--;
    }

    // 5. Swap
    std::swap(s[i], s[j]);

    // 6. Sort (Reverse) the Suffix
    // Reverse the part of the string *after* the pivot position 'i'
    std::reverse(s.begin() + i + 1, s.end());

    // 7. Convert back to long
    // Using stoll for "string to long long", which handles 'long'
    return std::stoll(s);
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
