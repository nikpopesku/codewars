#include "../cw_compat.hpp"
#include <vector>

using namespace std;

vector<int> the_lift(const vector<vector<int> > &queues, int capacity) {
    return {};
}

Describe(Sample_Tests) {
    It(Tests) {
        vector<vector<int> > queues;
        vector<int> result;

        queues = {{}, {}, {5, 5, 5}, {}, {}, {}, {}};
        result = {0, 2, 5, 0};
        Assert::That(the_lift(queues, 5), Equals(result));

        queues = {{}, {}, {1, 1}, {}, {}, {}, {}};
        result = {0, 2, 1, 0};
        Assert::That(the_lift(queues, 5), Equals(result));

        queues = {{}, {3}, {4}, {}, {5}, {}, {}};
        result = {0, 1, 2, 3, 4, 5, 0};
        Assert::That(the_lift(queues, 5), Equals(result));

        queues = {{}, {0}, {}, {}, {2}, {3}, {}};
        result = {0, 5, 4, 3, 2, 1, 0};
        Assert::That(the_lift(queues, 5), Equals(result));
    }
};
