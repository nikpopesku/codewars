#include "../cw_compat.hpp"
#include <vector>

using namespace std;

struct PairHash {
    size_t operator()(const pair<int, int> &p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

bool validate_battlefield(vector<vector<int> > field) {
    unordered_set<pair<int, int>, PairHash> s;

    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
            if (s.count({row, col}) == 0) {
            }
        }
    }
}


Describe(your_validate_battlefield_function) {
    It(should_work_for_a_sample_test_case) {
        Assert::That(validate_battlefield(vector{
                         vector{1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                         vector{1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
                         vector{1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
                         vector{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         vector{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                         vector{0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                         vector{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                         vector{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                         vector{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                         vector{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                     }), Equals(true));
    }
};
