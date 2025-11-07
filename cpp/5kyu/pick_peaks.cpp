#include "../cw_compat.hpp"
#include <vector>

using namespace std;

struct PeakData {
    vector<int> pos, peaks;
};

PeakData pick_peaks(const std::vector<int> &v) {
    bool local_max_left = false;
    PeakData pd;
    int local_max = 0;
    int local_max_peak = 0;

    for (int i = 1; i < static_cast<int>(v.size()); ++i) {
        if (v[i] > v[i-1]) {
            local_max_left = true;
            local_max = i;
            local_max_peak = v[i];

            continue;
        }
        if (v[i] < v[i-1] && local_max_left) {
            pd.pos.push_back(local_max);
            pd.peaks.push_back(local_max_peak);
            local_max_left = false;
        }
    }

    return pd;
}

Describe(your_pick_peaks_function) {
    It(should_pass_the_sample_test_cases_provided_in_the_description) {
        PeakData actual, expected;

        actual = pick_peaks(std::vector<int> {3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3});
        expected = {.pos = {3, 7}, .peaks = {6, 3}};
        Assert::That(actual, Equals(expected));

        actual = pick_peaks(std::vector<int> {1, 2, 2, 2, 1});
        expected = {.pos = {1}, .peaks = {2}};
        Assert::That(actual, Equals(expected));

        actual = pick_peaks(std::vector<int> {1, 2, 2, 2, 3});
        expected = {.pos = {}, .peaks = {}};
        Assert::That(actual, Equals(expected));
    }
};