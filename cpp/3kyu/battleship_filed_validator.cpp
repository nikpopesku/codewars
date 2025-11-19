#include "../cw_compat.hpp"
#include <vector>

using namespace std;

bool validate_battlefield(std::vector< std::vector<int> > field) {
    // Write your magic here ;)
    return true;
}


Describe(your_validate_battlefield_function) {
    It(should_work_for_a_sample_test_case) {
        Assert::That(validate_battlefield(std::vector< std::vector<int> > {
          std::vector<int> {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
          std::vector<int> {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
          std::vector<int> {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
          std::vector<int> {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
          std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
          std::vector<int> {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
          std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
          std::vector<int> {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
          std::vector<int> {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
          std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        }), Equals(true));
    }
};