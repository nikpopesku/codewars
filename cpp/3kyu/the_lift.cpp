#include "../cw_compat.hpp"
#include <vector>

using namespace std;

bool move_direction(int floor, string direction, const vector<vector<int> > &queues) {
    return false;
}

vector<int> the_lift(const vector<vector<int> > &queues, int capacity) {
    int N = queues.size();
    vector response = {0};
    int lift_capacity = 0;
    int index = 0;
    int people = 0;
    int floor = 0;
    string direction = "up";

    for (auto &q: queues) {
        people += static_cast<int>(q.size());
    }

    while (index < people) {
        bool condition = direction == "up" ? floor < N : floor >= 0;

        while (condition) {
            if (!move_direction(floor, direction, queues)) {
                direction == "up" ? "down" : "up";
            }

            floor += direction == "up" ? 1 : -1;
        }



        if (!queues[index].empty()) {
            if (capacity - lift_capacity > 0) {
            }
        }
    }

    return response;
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
