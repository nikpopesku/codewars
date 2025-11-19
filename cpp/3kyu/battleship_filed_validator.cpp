#include "../cw_compat.hpp"
#include <vector>

using namespace std;

bool validate_battlefield(vector<vector<int> > field) {
}


Describe(your_validate_battlefield_function) {
    It(should_work_for_a_sample_test_case) {
        Assert::That(validate_battlefield(vector{
                         vector{1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                         vector{1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
                         vector{1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
                         vector{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         vector{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                         vector{0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                         vector{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                         vector{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                         vector{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                         vector{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                     }), Equals(true));
    }
};
