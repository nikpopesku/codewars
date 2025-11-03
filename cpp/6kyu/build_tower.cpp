#include "../cw_compat.hpp"
#include <string>
#include <vector>

std::vector<std::string> towerBuilder(unsigned nFloors) {
    return std::vector<std::string>();
}

#include <string>
#include <vector>

Describe(Tests)
{
    It(ExampleTest1)
    {
        std::vector<std::string> expected = { "*" };

        std::vector<std::string> actual = towerBuilder(1);

        Assert::That(actual, Is().EqualTo(expected));
    }

    It(ExampleTest2)
    {
        std::vector<std::string> expected = { " * ", "***" };

        std::vector<std::string> actual = towerBuilder(2);

        Assert::That(actual, Is().EqualTo(expected));
    }

    It(ExampleTest3)
    {
        std::vector<std::string> expected = { "  *  ", " *** ", "*****" };

        std::vector<std::string> actual = towerBuilder(3);

        Assert::That(actual, Is().EqualTo(expected));
    }
};