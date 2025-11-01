#include <string>
#include <vector>
#include "cw_compat.hpp"

using namespace std;


string likes(const vector<string>& names)
{
    if (names.empty())
    {
        return "no one likes this";
    }

    if (names.size() == 1)
    {
        return names[0] + " likes this";
    }

    if (names.size() == 2)
    {
        return names[0] + " and " + names[1] + " like this";
    }

    if (names.size() == 3)
    {
        return names[0] + ", " + names[1] + " and " + names[2] + " like this";
    }

    return names[0] + ", " + names[1] + " and " + to_string(names.size() - 2) + " others like this";
}


Describe(sample_tests)
{
    It(should_return_correct_text)
    {
        Assert::That(likes({}), Equals("no one likes this"));
        Assert::That(likes({"Peter"}), Equals("Peter likes this"));
        Assert::That(likes({"Jacob", "Alex"}), Equals("Jacob and Alex like this"));
        Assert::That(likes({"Max", "John", "Mark"}), Equals("Max, John and Mark like this"));
        Assert::That(likes({"Alex", "Jacob", "Mark", "Max"}), Equals("Alex, Jacob and 2 others like this"));
    }
};
