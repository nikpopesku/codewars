#include "../cw_compat.hpp"
#include <climits>

using namespace std;

int path_finder(const string& maze)
{
    stringstream ss(maze);
    string line;
    vector<string> lines;
    while (getline(ss, line, '\n'))
    {
        lines.push_back(line);
    }

    const int N = static_cast<int>(lines.size());

    vector dp(N, vector(N, INT_MAX));


    const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    stack<tuple<int, int, int>> st;
    st.emplace(0, 0, 0);

    while (!st.empty())
    {
        auto [row, col, count] = st.top();
        st.pop();

        if (dp[row][col] > count)
        {
            dp[row][col] = count;

            for (const auto& [fst, snd] : directions)
            {
                pair nd = {row + fst, col + snd};
                if (nd.first >= 0 && nd.first < N && nd.second >= 0 && nd.second < N)
                {
                    st.emplace(nd.first, nd.second, count + abs((lines[nd.first][nd.second] - '0') - dp[row][col]));
                }
            }
        }
    }

    return dp[N - 1][N - 1];
}

Describe(example_tests)
{
    It(should_work_for_basic_tests)
    {
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

        // string s3 =
pp(s7), Equals(4));
    }
};
