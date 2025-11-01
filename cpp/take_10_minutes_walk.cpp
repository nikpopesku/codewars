#include "cw_compat.hpp"
#include<vector>

bool isValidWalk(std::vector<char> walk) {
    //your code here
}

using V = std::vector<char>;

Describe(IsValidWalk)
{
    It(BasicTests)
    {
        Assert::That(isValidWalk(V{'n'}), Equals(false));
        Assert::That(isValidWalk(V{'n','s','n','s','n','s','n','s','n','s'}), Equals(true));
        Assert::That(isValidWalk(V{'n','s'}), Equals(false));
        Assert::That(isValidWalk(V{'n','s','n','s','n','s','n','s','n','s','n','s'}), Equals(false));
        Assert::That(isValidWalk(V{'e','w','e','w','n','s','n','s','e','w'}), Equals(true));
        Assert::That(isValidWalk(V{'n','s','e','w','n','s','e','w','n','s','e','w','n','s','e','w'}), Equals(false));
        Assert::That(isValidWalk(V{'n','s','e','w','n','s','e','w','n','s'}), Equals(true));
        Assert::That(isValidWalk(V{'s','e','w','n','n','s','e','w','n','s'}), Equals(true));
        Assert::That(isValidWalk(V{'n','s','n','s','n','s','n','s','n','n'}), Equals(false));
        Assert::That(isValidWalk(V{'e','e','e','w','n','s','n','s','e','w'}), Equals(false));
    }
};