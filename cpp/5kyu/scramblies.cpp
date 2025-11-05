#include "../cw_compat.hpp"
#include <array>
#include <map>

using namespace std;

int score(const std::array<unsigned, 5> &dice) {
    map<unsigned, int> mp;

    for (const unsigned &d: dice) {
        ++mp[d];
    }

    int response = 0;

    while (true) {
        const int response_before = response;

        for (auto &[fst, snd]: mp) {
            if (fst == 1 && snd >= 3) {
                mp[fst] -= 3;
                response += 1000;
            }
            if (fst == 6 && snd >= 3) {
                mp[fst] -= 3;
                response += 600;
            }
            if (fst == 5 && snd >= 3) {
                mp[fst] -= 3;
                response += 500;
            }
            if (fst == 4 && snd >= 3) {
                mp[fst] -= 3;
                response += 400;
            }
            if (fst == 3 && snd >= 3) {
                mp[fst] -= 3;
                response += 300;
            }
            if (fst == 2 && snd >= 3) {
                mp[fst] -= 3;
                response += 200;
            }
            if (fst == 1 && snd >= 1) {
                --mp[fst];
                response += 100;
            }
            if (fst == 5 && snd >= 1) {
                --mp[fst];
                response += 50;
            }
        }

        if (response == response_before) {
            break;
        }
    }

    return response;
}


int score(const std::array<unsigned, 5> &dice);

Describe(ScorerFunction) {
    It(should_value_this_as_worthless) {
        std::array<unsigned, 5> dice = {2, 3, 4, 6, 2};
        Assert::That(score(dice), Equals(0));
    }

    It(should_value_this_triplet_correctly) {
        std::array<unsigned, 5> dice = {4, 4, 4, 3, 3};
        Assert::That(score(dice), Equals(400));
    }

    It(should_value_this_mixed_set_correctly) {
        std::array<unsigned, 5> dice = {2, 4, 4, 5, 4};
        Assert::That(score(dice), Equals(450));
    }
};
