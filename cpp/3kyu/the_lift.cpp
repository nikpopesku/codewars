#include "../cw_compat.hpp"
#include <vector>
#include <unordered_set>

using namespace std;

enum DIRECTIONS { UP, DOWN };

bool change_direction(const int floor, const DIRECTIONS direction, const vector<vector<int>>& queues,
                      const vector<int>& people_in_lift, const int N)
{
    if (direction == DOWN && floor == 0)
    {
        return true;
    }

    if (direction == UP && floor == N - 1)
    {
        return true;
    }

    for (auto& person : people_in_lift)
    {
        if (direction == UP && person > floor)
        {
            return false;
        }

        if (direction == DOWN && person < floor)
        {
            return false;
        }
    }

    if (direction == UP)
    {
        for (int i = floor; i < N; ++i)
        {
            if (!queues[i].empty())
            {
                return false;
            }
        }
    }

    if (direction == DOWN)
    {
        for (int i = floor; i >= 0; --i)
        {
            if (queues[i].empty())
            {
                return false;
            }
        }
    }


    return true;
}

vector<int> the_lift(vector<vector<int>>& queues, int capacity)
{
    const int N = static_cast<int>(queues.size());
    vector<int> response = {};
    int people_transported = 0;
    int people_total = 0;
    vector<int> people_in_lift;
    int floor = 0;
    DIRECTIONS direction = UP;

    if (queues[0].empty())
    {
        response.push_back(0);
    }

    for (auto& q : queues)
    {
        people_total += static_cast<int>(q.size());
    }

    while (people_transported < people_total)
    {
        bool still_move = direction == UP ? floor < N : floor >= 0;

        while (still_move)
        {
            if (change_direction(floor, direction, queues, people_in_lift, N))
            {
                direction = direction == UP ? DOWN : UP;
                continue;
            }

            bool add_floor_to_response = false;

            if (!people_in_lift.empty())
            {
                auto it = people_in_lift.begin();
                while (it != people_in_lift.end())
                {
                    if (*it == floor)
                    {
                        people_in_lift.erase(it++);
                        add_floor_to_response = true;
                        ++people_transported;
                    }
                    else
                    {
                        ++it;
                    }
                }
            }

            vector<int> got_in_lift;
            for (int i = 0; i < static_cast<int>(queues[floor].size()); ++i)
            {
                auto person = queues[floor][i];

                if (static_cast<int>(people_in_lift.size()) < capacity)
                {
                    if ((person > floor && direction == UP) || (person < floor && direction == DOWN))
                    {
                        people_in_lift.push_back(person);
                        got_in_lift.push_back(i);
                        add_floor_to_response = true;
                    }
                }
            }

            for (const auto& p_in_lift : got_in_lift)
            {
                for (auto it = queues[floor].begin(); it != queues[floor].end(); ++it)
                {
                    if (*it == p_in_lift)
                    {
                        queues[floor].erase(it);
                    }
                }
            }

            if (add_floor_to_response)
            {
                response.push_back(floor);
            }

            floor += direction == UP ? 1 : -1;
            still_move = direction == UP ? floor < N : floor >= 0;

            if (people_transported == people_total)
            {
                break;
            }
        }
    }

    if (response[response.size() - 1] != 0)
    {
        response.push_back(0);
    }

    return response;
}

Describe(Sample_Tests)
{
    It(Tests)
    {
        vector<vector<int>> queues;
        vector<int> result;

        queues = {{}, {}, {5, 5, 5}, {}, {}, {}, {}};
        result = {0, 2, 5, 0};
        Assert::That(the_lift(queues, 5), Equals(result));

        // queues = {{}, {}, {1, 1}, {}, {}, {}, {}};
        // result = {0, 2, 1, 0};
        // Assert::That(the_lift(queues, 5), Equals(result));
        //
        // queues = {{}, {3}, {4}, {}, {5}, {}, {}};
        // result = {0, 1, 2, 3, 4, 5, 0};
        // Assert::That(the_lift(queues, 5), Equals(result));
        //
        // queues = {{}, {0}, {}, {}, {2}, {3}, {}};
        // result = {0, 5, 4, 3, 2, 1, 0};
        // Assert::That(the_lift(queues, 5), Equals(result));
    }
};
