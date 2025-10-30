#include  <../kata/mumbling.cpp>
#include "cw_compat.hpp"

void testequal(std::string ans, std::string sol) {
    Assert::That(ans, Equals(sol));
}
static void dotest(std::string s, std::string expected)
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
