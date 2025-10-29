#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"       // Include the Catch2 header file

int quarter_of(const int month){
    return ((month - 1) / 3) + 1;
}

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