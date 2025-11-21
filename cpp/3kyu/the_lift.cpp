#include "../cw_compat.hpp"
#include <vector>

using namespace std;

enum DIRECTIONS { UP, DOWN };

bool change_direction(const int floor, DIRECTIONS direction, const vector<vector<int> > &queues,
                      const set<int> &people_in_lift, const int N) {
    if (direction == DOWN && floor == 0) {
        return true;
    }

    if (direction == UP && floor == N - 1) {
        return true;
    }

    for (auto &person: people_in_lift) {
        if (direction == UP && person > floor) {
            return false;
        }

        if (direction == DOWN && person < floor) {
            return false;
        }
    }

    if (direction == UP) {
        for (int i = floor; i < N; ++i) {
            for (auto &person: queues[i]) {
                if (person > floor) {
                    return false;
                }
            }
        }
    }

    if (direction == DOWN) {
        for (int i = floor; i >= 0; --i) {
            for (auto &person: queues[i]) {
                if (person < floor) {
                    return false;
                }
            }
        }
    }


    return true;
}

vector<int> the_lift(vector<vector<int> > &queues, int capacity) {
    const int N = queues.size();
    vector response = {0};
    int people_transported = 0;
    int people_total = 0;
    set<int> people_in_lift;
    int floor = 0;
    DIRECTIONS direction = UP;

    for (auto &q: queues) {
        people_total += static_cast<int>(q.size());
    }

    while (people_transported < people_total) {
        const bool move_not_finish = direction == UP ? floor < N : floor >= 0;

        while (move_not_finish) {
            if (change_direction(floor, direction, queues, people_in_lift, N)) {
                direction == UP ? DOWN : UP;
                continue;
            }

            for (auto &person: people_in_lift) {
                if (person == floor) {
                    people_in_lift.erase(person);
                }
            }

            vector<int> got_in_lift;
            for (int i = 0; i < static_cast<int>(queues[floor].size()); ++i) {
                auto person = queues[floor][i];

                if (static_cast<int>(people_in_lift.size()) < capacity) {
                    if (person > floor && direction == UP) {
                        people_in_lift.insert(person);
                        got_in_lift.push_back(i);
                        ++people_transported;
                    }
                    if (person < floor && direction == DOWN) {
                        people_in_lift.insert(person);
                        got_in_lift.push_back(i);
                        ++people_transported;
                    }
                }
            }

            for (const auto &person: got_in_lift) {
                queues[floor].erase(queues[floor].begin() + person);
            }

            floor += direction == UP ? 1 : -1;
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
