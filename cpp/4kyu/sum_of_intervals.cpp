#include "../cw_compat.hpp"
#include <vector>
#include <utility>

using namespace std;

int sum_intervals(vector<pair<int, int>> intervals)
{
    sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.first < b.first)
        {
            return 1;
        }

        if (a.first > b.first)
        {
            return -1;
        }

        if (a.second < b.second)
        {
            return 1;
        }

        if (a.second < b.second)
        {
            return -1;
        }

        return 0;
    });

    int response = 0;

    for (auto& [fst, snd] : intervals)
    {
        response += snd - fst;
    }

    return response;
}

Describe(Sample_Tests)
{
    It(Tests)
    {
        vector<pair<int, int>> intervals = {{1, 5}};
        Assert::That(sum_intervals(intervals), Equals(4));

        intervals = {{1, 5}, {6, 10}};
        Assert::That(sum_intervals(intervals), Equals(8));

        intervals = {{1, 4}, {7, 10}, {3, 5}};
        Assert::That(sum_intervals(intervals), Equals(7));
    }

    It(Large_Intervals)
    {
        vector<pair<int, int>> intervals = {{-1000000000, 1000000000}};
        Assert::That(sum_intervals(intervals), Equals(2000000000));

        intervals = {{0, 20}, {-100000000, 10}, {30, 40}};
        Assert::That(sum_intervals(intervals), Equals(100000030));
    }
};
