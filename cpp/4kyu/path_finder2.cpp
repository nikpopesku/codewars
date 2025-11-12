#include "../cw_compat.hpp"
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int path_finder(const string &maze) {
    stringstream ss(maze);
    string s;
    vector<string> mz;
    unordered_set<string> visited;
    int N = mz.size();

    while (std::getline(ss, s, ',')) {
        mz.push_back(s);
    }

    pair position = {0, 0};
    stack<tuple<int, int, int> > st;
    st.push({0, 0, 0});

    vector<pair<int, int> > directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int response = -1;

    while (!st.empty()) {
        auto [i, j, count] = st.top();
        st.pop();
        if (mz[i][j] == 'W') {
            continue;
        }

        if (i == N - 1 && j == N - 1) {
            if (response == -1) {
                response = count;
            } else {
                response = min(response, count);
            }
        }

        for (auto &[fst, snd]: directions) {
            const pair nd = {position.first + fst, position.second + snd};

            if (nd.first >= 0 && nd.first < static_cast<int>(mz.size())
                && nd.second >= 0 && nd.second < static_cast<int>(mz.size()) && mz[nd.first][nd.second] != 'W' &&
                visited.count(to_string(nd.first) + '_' + to_string(nd.second)) == 0) {
                visited.insert(to_string(nd.first) + '_' + to_string(nd.second));
                st.push({nd.first, nd.second, count + 1});
            }
        }

        s = to_string(i) + '_' + to_string(j);
        if (visited.count(s)) {
            continue;
        }

        st.push({i, j});
    }

    return -1;
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
