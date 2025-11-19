#include "../cw_compat.hpp"
#include <vector>

using namespace std;

struct PairHash {
    size_t operator()(const pair<int, int> &p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

void find_ship(stack<pair<int, int>> &st, unordered_set<pair<int, int>, PairHash> &visited) {
    vector<pair<int, int> > directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!st.empty()) {
        auto elem = st.top();
        st.pop();
    }
}

bool validate_battlefield(const vector<vector<int> > &field) {
    unordered_set<pair<int, int>, PairHash> visited;
    unordered_map<int, int> mp;
    stack<pair<int, int> > st;


    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
            if (visited.count({row, col}) == 0) {
                visited.insert({row, col});

                if (field[row][col] == 1) {
                    st.emplace(row, col);
                    find_ship(st, visited);
                }
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
