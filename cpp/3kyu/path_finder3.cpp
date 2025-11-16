#include "../cw_compat.hpp"

using namespace std;

int path_finder(string maze)
{
    // your code here... enjoy!
    return -1;
}

string s1 =

    "000\n"
    "000\n"
    "000";

string s2 =

    "010\n"
    "010\n"
    "010";

string s3 =

    "010\n"
    "101\n"
    "010";

string s4 =

    "0707\n"
    "7070\n"
    "0707\n"
    "7070";

string s5 =

    "700000\n"
    "077770\n"
    "077770\n"
    "077770\n"
    "077770\n"
    "000007";

string s6 =

    "777000\n"
    "007000\n"
    "007000\n"
    "007000\n"
    "007000\n"
    "007777";

string s7 =

    "000000\n"
    "000000\n"
    "000000\n"
    "000010\n"
    "000109\n"
    "001010";

Describe(example_tests)
{
    It(should_work_for_basic_tests)
    {
        Assert::That(path_finder(s1), Equals(0));
        Assert::That(path_finder(s2), Equals(2));
        Assert::That(path_finder(s3), Equals(4));
        Assert::That(path_finder(s4), Equals(42));
        Assert::That(path_finder(s5), Equals(14));
        Assert::That(path_finder(s6), Equals(0));
        Assert::That(path_finder(s7), Equals(4));
    }
};
