#include "cw_compat.hpp"
#include <string>

using namespace std;

class Accumul {
public:
    static std::string accum(const std::string &s) {
        string response;
        int counter = 1;

        for (const auto c: s) {
            for (int i = 0; i < counter; ++i) {
                response += i == 0 ? toupper(c) : tolower(c);
            }

            if (counter < static_cast<int>(s.size())) {
                response += '-';
            }

            ++counter;
        }

        return response;
    }
};

void testequal(const std::string& ans, const std::string& sol) {
    Assert::That(ans, Equals(sol));
}
static void dotest(const std::string& s, const std::string& expected)
{
    testequal(Accumul::accum(s), expected);
}
Describe(accum_Tests)
{
    It(Fixed_Tests)
    {
        dotest("ZpglnRxqenU", "Z-Pp-Ggg-Llll-Nnnnn-Rrrrrr-Xxxxxxx-Qqqqqqqq-Eeeeeeeee-Nnnnnnnnnn-Uuuuuuuuuuu");
        dotest("NyffsGeyylB", "N-Yy-Fff-Ffff-Sssss-Gggggg-Eeeeeee-Yyyyyyyy-Yyyyyyyyy-Llllllllll-Bbbbbbbbbbb");
    }
};
