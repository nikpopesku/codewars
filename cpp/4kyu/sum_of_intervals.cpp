#include "../cw_compat.hpp"
#include <vector>
#include <utility>

using namespace std;

int sum_intervals(std::vector<std::pair<int, int>> intervals) {
    return 0;
}

Describe(Sample_Tests)
{
    It(Tests)
    {
        std::vector<std::pair<int, int>> intervals = {{1, 5}};
        Assert::That(sum_intervals(intervals), Equals(4));

        intervals = {{1, 5}, {6, 10}};
        Assert::That(sum_intervals(intervals), Equals(8));

        intervals = {{1, 4}, {7, 10}, {3, 5}};
        Assert::That(sum_intervals(intervals), Equals(7));
    }

    It(Large_Intervals)
    {
        std::vector<std::pair<int, int>> intervals = {{-1000000000, 1000000000}};
        Assert::That(sum_intervals(intervals), Equals(2000000000));

        intervals = {{0, 20}, {-100000000, 10}, {30, 40}};
        Assert::That(sum_intervals(intervals), Equals(100000030));
    }
};