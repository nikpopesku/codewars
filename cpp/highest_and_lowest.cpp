#include "cw_compat.hpp"
#include <string>
#include <sstream>

using namespace std;

string highAndLow(const string& numbers)
{
    stringstream ss(numbers);
    string word;
    int min_value, max_value;
    int counter = 0;

    while (ss >> word)
    {
        if (counter == 0)
        {
            min_value = max_value = stoi(word);
            ++counter;
            continue;
        }

        int value = stoi(word);
        min_value = min(min_value, value);
        max_value = max(max_value, value);
    }

    return to_string(max_value) + ' ' + to_string(min_value);
}

Describe(ExampleTests)
{
    It(Test1)
    {
        Assert::That(highAndLow("8 3 -5 42 -1 0 0 -9 4 7 4 -4"), Equals("42 -9"));
    }
    It(Test2)
    {
        Assert::That(highAndLow("1 2 3"), Equals("3 1"));
    }
};
