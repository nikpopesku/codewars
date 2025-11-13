#include "../cw_compat.hpp"
#include <string>

using namespace std;

int get_row(char a) {
    switch (a) {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
        default:
            throw logic_error("Unknown value provided " . a);
    }
}

int knight(string start, string finish) {

}

Describe(Sample_Tests)
{
    It(Tests)
    {
        Assert::That(knight("a1", "c1"), Equals(2));
        Assert::That(knight("a1", "f1"), Equals(3));
        Assert::That(knight("a1", "f3"), Equals(3));
        Assert::That(knight("a1", "f4"), Equals(4));
        Assert::That(knight("a1", "f7"), Equals(5));
    }
};