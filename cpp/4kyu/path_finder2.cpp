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

    while (std::getline(ss, s, ',')) {
        mz.push_back(s);
    }


    for (int i = 0; i < static_cast<int>(mz.size()); ++i) {
        for (int j = 0; j < static_cast<int>(mz[0].size()); ++j) {
            if (mz[i][j] == 'W') {
                continue;
            }

            s = to_string(i) + '_' + to_string(j);
            if (visited.count(s)) {
                continue;
            }
        }
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
