// Declaration to use the function implemented in quarter_of_the_year.cpp
int quarter_of(const int month);
#include "cw_compat.hpp"

Describe(Sample_tests) {
    It(Base_cases) {
        Assert::That(quarter_of(1), Equals(1));
        Assert::That(quarter_of(3), Equals(1));
        Assert::That(quarter_of(5), Equals(2));
        Assert::That(quarter_of(7), Equals(3));
        Assert::That(quarter_of(9), Equals(3));
        Assert::That(quarter_of(11), Equals(4));
    }
};