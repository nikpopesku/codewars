#include "../cw_compat.hpp"
#include <vector>

using namespace std;

vector<int> move_zeroes(const vector<int>& input) {
    // your code here
    return {};
}

Describe(Fixed_tests) {
    It(Mixed_data) {
        Assert::That(move_zeroes(vector{1, 2, 0, 1, 0, 1, 0, 3, 0, 1}),
                     Equals((vector{1, 2, 1, 1, 3, 1, 0, 0, 0, 0})));
    }
    It(All_zeroes) {
        Assert::That(move_zeroes(vector{0, 0, 0, 0, 0, 0}),
                     Equals((vector{0, 0, 0, 0, 0, 0})));
    }
    It(No_zeroes) {
        Assert::That(move_zeroes(vector{1, 2, 5, 1, 5, 1, 5, 3, 2, 1}),
                     Equals((vector{1, 2, 5, 1, 5, 1, 5, 3, 2, 1})));
    }
};