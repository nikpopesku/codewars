#include "../cw_compat.hpp"
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int path_finder(const string &maze) {
    stringstream ss(maze);
    string s;
    vector<string> mz;

    while (std::getline(ss, s, '\n')) {
        mz.push_back(s);
    }

    int N = static_cast<int>(mz.size());
    stack<tuple<int, int, int> > st;

    if (mz[0][0] != 'W') {
        st.emplace(0, 0, 0);
    }

    vector dp(N, vector(N, -1));
    dp[0][0] = 0;

    vector<pair<int, int> > directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!st.empty()) {
        auto [row, col, count] = st.top();
        st.pop();

        bool adjusted = false;

        if (dp[row][col] == -1 || count < dp[row][col]) {
            dp[row][col] = count;
            adjusted = true;
        }

        for (auto &[fst, snd]: directions) {
            const pair nd = {row + fst, col + snd};

            if (nd.first >= 0 && nd.first < N && nd.second >= 0 &&
                nd.second < N && mz[nd.first][nd.second] == '.' && adjusted) {
                st.emplace(nd.first, nd.second, dp[row][col] + 1);
            }
        }
    }

    return dp[N - 1][N - 1];
}


Describe(your_path_finder_function) {
    It(should_work_for_a_few_simple_fixed_tests_involving_small_mazes) {
        /*
          Maze:
            .W.
            .W.
            ...
        */
        Assert::That(path_finder(".W.\n.W.\n..."), Equals(4));
        /*
          Maze:
            .W.
            .W.
            W..
        */
        Assert::That(path_finder(".W.\n.W.\nW.."), Equals(-1));
        /*
          Maze:
            ......
            ......
            ......
            ......
            ......
            ......
        */
        Assert::That(path_finder("......\n......\n......\n......\n......\n......"), Equals(10));
        /*
          Maze:
            ......
            ......
            ......
            ......
            .....W
            ....W.
        */
        Assert::That(path_finder("......\n......\n......\n......\n.....W\n....W."), Equals(-1));
    }
};
