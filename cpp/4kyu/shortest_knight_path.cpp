#include "../cw_compat.hpp"
#include <string>

using namespace std;

int get_row(const char a) {
    switch (a) {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
        default:
            throw logic_error(string("Unknown value provided ") + a);
    }
}

int knight(const string &start, const string &finish) {
    pair bg = {get_row(start[0]), start[1] - '0'};
    const pair end = {get_row(finish[0]), finish[1] - '0'};

    vector dp(8, vector(8, 64));
    stack<tuple<int, int, int> > st;
    st.emplace(bg.first, bg.second, 0);
    vector<pair<int, int> > directions = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

    while (!st.empty()) {
        auto [row, col, count] = st.top();
        st.pop();

        if (count < dp[row][col]) {
            dp[row][col] = count;

            for (auto &[fst, snd]: directions) {
                pair nd = {fst + row, snd + col};

                if (nd.first >= 0 && nd.first < 8 && nd.second >= 0 && nd.second < 8) {
                    st.emplace(nd.first, nd.second, count + 1);
                }
            }
        }
    }

    return dp[end.first][end.second];
}

Describe(Sample_Tests) {
    It(Tests) {
        Assert::That(knight("a1", "c1"), Equals(2));
        Assert::That(knight("a1", "f1"), Equals(3));
        Assert::That(knight("a1", "f3"), Equals(3));
        Assert::That(knight("a1", "f4"), Equals(4));
        Assert::That(knight("a1", "f7"), Equals(5));
    }
};
