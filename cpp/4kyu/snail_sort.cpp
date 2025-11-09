#include "../cw_compat.hpp"
#include <vector>

using namespace std;

vector<int> snail(const vector<vector<int>>& snail_map)
{
}


Describe(Sample_Tests)
{
    It(Tests)
    {
        vector<vector<int>> v = {{}};
        vector<int> expected = {};
        Assert::That(snail(v), Equals(expected));

        v = {{1}};
        expected = {1};
        Assert::That(snail(v), Equals(expected));

        v = {{1, 2}, {4, 3}};
        expected = {1, 2, 3, 4};
        Assert::That(snail(v), Equals(expected));

        v = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
        expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        Assert::That(snail(v), Equals(expected));

        v = {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
        expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
        Assert::That(snail(v), Equals(expected));
    }
};
