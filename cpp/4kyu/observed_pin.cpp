#include "../cw_compat.hpp"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<std::string> get_pins(std::string observed) {
    return {};
}


Describe(Sample_Tests)
{
    It(Tests)
    {
        std::vector<std::string> output = get_pins("8"); std::sort(output.begin(), output.end());
        std::vector<std::string> result = {"0", "5", "7", "8", "9"};
        Assert::That(output, Equals(result));

        output = get_pins("11"); std::sort(output.begin(), output.end());
        result = {"11", "12", "14", "21", "22", "24", "41", "42", "44"};
        Assert::That(output, Equals(result));

        output = get_pins("369"); std::sort(output.begin(), output.end());
        result = {"236", "238", "239", "256", "258", "259", "266", "268", "269", "296", "298", "299", "336", "338", "339", "356", "358", "359", "366", "368", "369", "396", "398", "399", "636", "638", "639", "656", "658", "659", "666", "668", "669", "696", "698", "699"};
        Assert::That(output, Equals(result));
    }
};