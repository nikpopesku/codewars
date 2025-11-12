#include "../cw_compat.hpp"
#include <iostream>
#include <string>

using namespace std;

int path_finder(string maze) {
    // TODO: Return the minimal number of steps required to reach the exit located at
    // (n - 1, n - 1) from the initial position (0, 0) in an n × n maze if possible and
    // -1 otherwise
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