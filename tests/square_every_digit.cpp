// Declaration to use the function implemented in quarter_of_the_year.cpp
int square_digits(int num);
#include "cw_compat.hpp"

Describe(Square_Every_Digit)
{
    It(Sample_tests)
    {
        Assert::That(square_digits(3212), Equals(9414));
        Assert::That(square_digits(2112), Equals(4114));
        Assert::That(square_digits(0), Equals(0));
        Assert::That(square_digits(13579), Equals(19254981));
        Assert::That(square_digits(24680), Equals(41636640));
    }
};
