#include "../cw_compat.hpp"
#include <string>
#include <vector>

using namespace std;

vector<string> towerBuilder(const unsigned nFloors)
{
    vector<string> response(nFloors);

    for (unsigned int i = 0; i < nFloors; ++i)
    {
        for (unsigned int j = 0; j < nFloors - i - 1; ++j)
        {
            response[i] += ' ';
        }

        for (unsigned int j = 0; j < i + 1; ++j)
        {
            response[i] += '*';
        }

        for (unsigned int j = 0; j < nFloors - i - 1; ++j)
        {
            response[i] += ' ';
        }
    }

    return response;
}

Describe(Tests)
{
    It(ExampleTest1)
    {
        vector<string> expected = {"*"};

        const vector<string> actual = towerBuilder(1);

        Assert::That(actual, Equals(expected));
    }

    It(ExampleTest2)
    {
        vector<string> expected = {" * ", "***"};

        const vector<string> actual = towerBuilder(2);

        Assert::That(actual, Equals(expected));
    }

    It(ExampleTest3)
    {
        vector<string> expected = {"  *  ", " *** ", "*****"};

        const vector<string> actual = towerBuilder(3);

        Assert::That(actual, Equals(expected));
    }
};
