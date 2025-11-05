#include "../cw_compat.hpp"
#include <string>
#include <unordered_map>

using namespace std;

bool scramble(const std::string &s1, const std::string &s2) {
    unordered_map<char, int> mp;

    for (const char &c: s2) {
        ++mp[c];
    }

    for (const char &c: s1) {
        if (mp.count(c)) {
            --mp[c];

            if (mp[c] == 0) {
                mp.erase(c);
            }
        }

        if (mp.empty()) {
            return true;
        }
    }

    return false;
}


Describe(Scramble) {
    It(BasicTests) {
        Assert::That(scramble("rkqodlw", "world"), Equals(true));
        Assert::That(scramble("cedewaraaossoqqyt", "codewars"), Equals(true));
        Assert::That(scramble("katas", "steak"), Equals(false));
        Assert::That(scramble("scriptjavx", "javascript"), Equals(false));
        Assert::That(scramble("scriptingjava", "javascript"), Equals(true));
        Assert::That(scramble("scriptsjava", "javascript"), Equals(true));
        Assert::That(scramble("javscripts", "javascript"), Equals(false));
        Assert::That(scramble("aabbcamaomsccdd", "commas"), Equals(true));
        Assert::That(scramble("commas", "commas"), Equals(true));
        Assert::That(scramble("sammoc", "commas"), Equals(true));
    }
};
