#include "../cw_compat.hpp"
#include <queue>
#include <climits>

using namespace std;

int path_finder(const string &maze) {
    stringstream ss(maze);
    string line;
    vector<string> lines;

    while (getline(ss, line, '\n')) {
        lines.push_back(line);
    }

    const int N = static_cast<int>(lines.size());

    vector dp(N, vector(N, INT_MAX));
    vector<pair<int, int> > directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<> > pq;
    pq.emplace(0, 0, 0);

    while (!pq.empty()) {
        auto [cost, row, col] = pq.top();
        pq.pop();

        if (cost > dp[row][col]) {
            continue;
        }

        if (row == N - 1 && col == N - 1) {
            return cost;
        }

        for (auto &[fst, snd]: directions) {
            pair nd = {row + fst, col + snd};

            if (nd.first >= 0 && nd.first < N && nd.second >= 0 && nd.second < N) {
                int new_cost = cost + abs((lines[nd.first][nd.second] - '0') - (lines[row][col] - '0'));

                if (new_cost < dp[nd.first][nd.second]) {
                    pq.emplace(new_cost, nd.first, nd.second);
                    dp[nd.first][nd.second] = new_cost;
                }
            }
        }
    }
}

Describe(example_tests) {
    It(should_work_for_basic_tests) {
        string s1 =

                "000\n"
                "000\n"
                "000";
        Assert::That(path_finder(s1), Equals(0));

        string s2 =

                "010\n"
                "010\n"
                "010";
        Assert::That(path_finder(s2), Equals(2));

        string s3 =

                "010\n"
                "101\n"
                "010";
        Assert::That(path_finder(s3), Equals(4));

        string s4 =

                "0707\n"
                "7070\n"
                "0707\n"
                "7070";
        Assert::That(path_finder(s4), Equals(42));

        string s5 =

                "700000\n"
                "077770\n"
                "077770\n"
                "077770\n"
                "077770\n"
                "000007";
        Assert::That(path_finder(s5), Equals(14));

        string s6 =

                "777000\n"
                "007000\n"
                "007000\n"
                "007000\n"
                "007000\n"
                "007777";
        Assert::That(path_finder(s6), Equals(0));

        string s7 =


                "000000\n"
                "000000\n"
                "000000\n"
                "000010\n"
                "000109\n"
                "001010";
        Assert::That(path_finder(s7), Equals(4));
    }
};
