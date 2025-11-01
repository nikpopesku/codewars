#include<vector>

using namespace std;

bool isValidWalk(const std::vector<char>& walk)
{
    std::pair coordinates = {0, 0};
    int counter = 0;

    for (const auto& c : walk)
    {
        ++counter;

        if (c == 'n')
        {
            coordinates.second += 1;

            continue;
        }

        if (c == 's')
        {
            coordinates.second -= 1;

            continue;
        }

        if (c == 'w')
        {
            coordinates.first -= 1;

            continue;
        }

        if (c == 'e')
        {
            coordinates.first += 1;
        }
    }

    return counter == 10 && coordinates.first == 0 && coordinates.second == 0;
}

using V = std::vector<char>;

#include "cw_compat.hpp"

Describe(IsValidWalk)
{
    It(BasicTests)
    {
        Assert::That(isValidWalk(V{'n'}), Equals(false));
        Assert::That(isValidWalk(V{'n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 's'}), Equals(true));
        Assert::That(isValidWalk(V{'n', 's'}), Equals(false));
        Assert::That(isValidWalk(V{'n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 's'}), Equals(false));
        Assert::That(isValidWalk(V{'e', 'w', 'e', 'w', 'n', 's', 'n', 's', 'e', 'w'}), Equals(true));
        Assert::That(isValidWalk(V{'n', 's', 'e', 'w', 'n', 's', 'e', 'w', 'n', 's', 'e', 'w', 'n', 's', 'e', 'w'}),
                     Equals(false));
        Assert::That(isValidWalk(V{'n', 's', 'e', 'w', 'n', 's', 'e', 'w', 'n', 's'}), Equals(true));
        Assert::That(isValidWalk(V{'s', 'e', 'w', 'n', 'n', 's', 'e', 'w', 'n', 's'}), Equals(true));
        Assert::That(isValidWalk(V{'n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 'n'}), Equals(false));
        Assert::That(isValidWalk(V{'e', 'e', 'e', 'w', 'n', 's', 'n', 's', 'e', 'w'}), Equals(false));
    }
};
