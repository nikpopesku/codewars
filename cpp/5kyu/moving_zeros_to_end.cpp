#include "../cw_compat.hpp"
#include <vector>

using namespace std;

vector<int> move_zeroes(const vector<int>& input)
{
    int index = 0;
    int index_no_zero = 0;
    vector<int> response = input;

    while (index < static_cast<int>(input.size()))
    {
        if (input[index] != 0)
        {
            if (index_no_zero != index)
            {
                response[index_no_zero] = response[index];
            }

            ++index_no_zero;
        }
        ++index;
    }

    for (int i = index_no_zero; i < static_cast<int>(input.size()); ++i)
    {
        response[i] = 0;
    }

    return response;
}

Describe(Fixed_tests)
{
    It(Mixed_data)
    {
        Assert::That(move_zeroes(vector{1, 2, 0, 1, 0, 1, 0, 3, 0, 1}),
                     Equals((vector{1, 2, 1, 1, 3, 1, 0, 0, 0, 0})));
    }
    It(All_zeroes)
    {
        Assert::That(move_zeroes(vector{0, 0, 0, 0, 0, 0}),
                     Equals((vector{0, 0, 0, 0, 0, 0})));
    }
    It(No_zeroes)
    {
        Assert::That(move_zeroes(vector{1, 2, 5, 1, 5, 1, 5, 3, 2, 1}),
                     Equals((vector{1, 2, 5, 1, 5, 1, 5, 3, 2, 1})));
    }
};
