#include "../cw_compat.hpp"

using namespace std;


class BestTravel {
public:
    static int mx;

    static int chooseBestSum(int t, int k, const vector<int> &ls) {
        backtrack(0, 0, 0, k, t);

        return mx;
    }

private:
    void static backtrack(const int count, const int index, const int sum, const int &k, const int &t,
                          const vector<int> &ls) {
        if (count == k && sum < t) {
            mx = max(mx, sum);
        }

        if (static_cast<int>(ls.size()) - 1 - index < k - count) {
            return;
        }

        for (int i = index; i < static_cast<int>(ls.size()); ++i) {
            backtrack(count + 1, i + 1, sum + ls[i], k, t);
        }
    }
};

int BestTravel::mx = 0;


void testequal(int ans, int sol) {
    Assert::That(ans, Equals(sol));
}

Describe(Tests) {
    It(Fixed_chooseBestSum) {
        vector<int> ts = {50, 55, 56, 57, 58};
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
