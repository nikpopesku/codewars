#include "cw_compat.hpp"

int solution(const int number)
{
    int response = 0;

    for (int i = 3; i < number; ++i)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            response += i;
        }
    }

    return response;
}

Describe(solution_algorithm)
{
    It(should_handle_basic_test_cases)
    {
        Assert::That(solution(10), Equals(23));
        Assert::That(solution(-10), Equals(0));
        Assert::That(solution(2), Equals(0));
        Assert::That(solution(9), Equals(14));
    }
};