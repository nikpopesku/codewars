#include <string>
#include <vector>
#include "cw_compat.hpp"

std::string likes(const std::vector<std::string> &names)
{
    return ""; // Do your magic!
}


#include <string>
#include <vector>

std::string likes(const std::vector<std::string> &names);

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