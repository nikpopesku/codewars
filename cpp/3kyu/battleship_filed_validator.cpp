#include "../cw_compat.hpp"
#include <vector>

using namespace std;

struct PairHash {
    size_t operator()(const pair<int, int> &p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

bool validate(set<pair<int, int>>& ship) {
    string directions, new_directions;
    pair<int, int> previous;

    for (auto & s: ship) {
        if (previous) {
            if (s.first == previous.first) {
                new_directions = 'horizontal';
            }

            if (s.second == previous.second) {
                new_directions = 'vertical';
            }

            if (new_directions.size() == 0) {
                return false;
            }

            if (directions.size() != 0 && new_directions != directions) {
                return false;
            }

            directions = new_directions;
        }
        previous = s;
    }

    return true;

}

int find_ship(stack<pair<int, int> > &st, unordered_set<pair<int, int>, PairHash> &visited,
              const vector<vector<int> > &field) {
    vector<pair<int, int> > directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    set<pair<int, int>> ship;

    while (!st.empty()) {
        auto [row, col] = st.top();
        st.pop();

        ship.insert({row, col});

        for (auto &[fst, snd]: directions) {
            const pair nd = {row + fst, col + snd};

            if (nd.first >= 0 && nd.first < 10 && nd.second >= 0 && nd.second < 10 && visited.count(nd) == 0) {
                visited.insert(nd);
                if (field[nd.first][nd.second] == 1) {
                    st.push(nd);
                }
            }
        }
    }
}

bool validate_battlefield(const vector<vector<int> > &field) {
    unordered_set<pair<int, int>, PairHash> visited;
    unordered_map<int, int> ship_mp;
    stack<pair<int, int> > st;


    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
            if (visited.count({row, col}) == 0) {
                visited.insert({row, col});

                if (field[row][col] == 1) {
                    st.emplace(row, col);
                    find_ship(st, visited, field);
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
