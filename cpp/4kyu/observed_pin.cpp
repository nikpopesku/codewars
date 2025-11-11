#include "../cw_compat.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> get_pins(string observed)
{
    unordered_map<char, vector<char>> mp{
        {'1', {'1', '2', '4'}},
        {'2', {'1', '2', '3', '5'}},
        {'3', {'2', '3', '6'}},
        {'4', {'1', '4', '5', '7'}},
        {'5', {'2', '4', '5', '6', '8'}},
        {'6', {'3', '5', '6', '9'}},
        {'7', {'4', '7', '8'}},
        {'8', {'0', '5', '7', '8', '9'}},
        {'9', {'6', '8', '9'}},
        {'0', {'0', '8'}},
    };
    return {};
}


Describe(Sample_Tests)
{
    It(Tests)
    {
        vector<string> output = get_pins("8");
        sort(output.begin(), output.end());
        vector<string> result = {"0", "5", "7", "8", "9"};
        Assert::That(output, Equals(result));

        output = get_pins("11");
        sort(output.begin(), output.end());
        result = {"11", "12", "14", "21", "22", "24", "41", "42", "44"};
        Assert::That(output, Equals(result));

        output = get_pins("369");
        sort(output.begin(), output.end());
        result = {
            "236", "238", "239", "256", "258", "259", "266", "268", "269", "296", "298", "299", "336", "338", "339",
            "356", "358", "359", "366", "368", "369", "396", "398", "399", "636", "638", "639", "656", "658", "659",
            "666", "668", "669", "696", "698", "699"
        };
        Assert::That(output, Equals(result));
    }
};
