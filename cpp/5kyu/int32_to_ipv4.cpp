#include "../cw_compat.hpp"
#include <string>

using namespace std;


std::string uint32_to_ip(uint32_t ip)
{
    // your code here
    return "";
}

Describe(test_cases)
{
    It(sample_tests)
    {
        Assert::That(uint32_to_ip(2154959208), Equals("128.114.17.104"));
        Assert::That(uint32_to_ip(0), Equals("0.0.0.0"));
        Assert::That(uint32_to_ip(2149583361), Equals("128.32.10.1"));
    }
};