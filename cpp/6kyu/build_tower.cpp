#include "../cw_compat.hpp"
#include <string>
#include <vector>

using namespace std;

vector<string> towerBuilder(unsigned nFloors)
{
    vector<string> response(nFloors);

    for (int i = 0; i < nFloors; ++i)
    {
        for (int j = 0; j < nFloors - i - 1; ++j)
        {
            response[i] += ' ';
        }

        for (int j = 0; j < i + 1; ++j)
        {
            response[i] += '*';
        }

        for (int j = 0; j < nFloors - i - 1; ++j)
        {
            response[i] += ' ';
        }
    }
}

Describe(Tests)
{
    It(ExampleTest1)
    {
        vector<string> expected = {"*"};

        const vector<string> actual = towerBuilder(1);

        Assert::That(actual, Is().EqualTo(expected));
    }

    It(ExampleTest2)
    {
        vector<string> expected = {" * ", "***"};

        const vector<string> actual = towerBuilder(2);

        Assert::That(actual, Is().EqualTo(expected));
    }

    It(ExampleTest3)
    {
        vector<string> expected = {"  *  ", " *** ", "*****"};

        const vector<string> actual = towerBuilder(3);

        Assert::That(actual, Is().EqualTo(expected));
    }
};
