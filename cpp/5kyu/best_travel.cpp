#include "../cw_compat.hpp"

using namespace std;


class BestTravel {
public:
    static int chooseBestSum(int t, int k, std::vector<int> &ls);
};


void testequal(int ans, int sol) {
    Assert::That(ans, Equals(sol));
}

Describe(Tests) {
    It(Fixed_chooseBestSum) {
        std::vector<int> ts = {50, 55, 56, 57, 58};
        int n = BestTravel::chooseBestSum(163, 3, ts);
        testequal(n, 163);
        ts = {50};
        n = BestTravel::chooseBestSum(163, 3, ts);
        testequal(n, -1);
        ts = {91, 74, 73, 85, 73, 81, 87};
        n = BestTravel::chooseBestSum(230, 3, ts);
        testequal(n, 228);
        n = BestTravel::chooseBestSum(331, 2, ts);
        testequal(n, 178);
        n = BestTravel::chooseBestSum(331, 4, ts);
        testequal(n, 331);
        n = BestTravel::chooseBestSum(331, 5, ts);
        testequal(n, -1);
        n = BestTravel::chooseBestSum(331, 1, ts);
        testequal(n, 91);
        n = BestTravel::chooseBestSum(700, 8, ts);
        testequal(n, -1);
    }
};
