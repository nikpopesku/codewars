#include "../cw_compat.hpp"
#include <string>

using namespace std;


string uint32_to_ip(const uint32_t ip) {
    string response;

    for (int i = 3; i >= 0; --i) {
        const uint32_t mx = 255 << (i * 8);
        uint32_t val = ip & mx;
        val = val >> (i * 8);
        response += to_string(val);

        if (i != 0) {
            response += ".";
        }
    }
    return response;
}

Describe(test_cases) {
    It(sample_tests) {
        Assert::That(uint32_to_ip(2154959208), Equals("128.114.17.104"));
        Assert::That(uint32_to_ip(0), Equals("0.0.0.0"));
        Assert::That(uint32_to_ip(2149583361), Equals("128.32.10.1"));
    }
};
