#include "cw_compat.hpp"
#include <string>
#include <set>

using namespace std;

bool is_isogram(const std::string &str) {
    set<char> s;

    for (auto c: str) {
        c = tolower(c);
        if (s.find(c) != s.end()) {
            return false;
        }

        s.insert(c);
    }

    return true;
}

Describe(sample_test_cases)
{
    It(should_handle_empty_strings)
    {
        Assert::That(is_isogram(""), Equals(true), ExtraMessage(R"(Incorrect result for input = "" (the empty string is a valid isogram):)"));
    }
    It(should_detect_single_letter_isograms)
    {
        Assert::That(is_isogram("a"), Equals(true), ExtraMessage(R"(Incorrect result for input = "a":)"));
        Assert::That(is_isogram("X"), Equals(true), ExtraMessage(R"(Incorrect result for input = "X":)"));
    }
    It(should_detect_longer_isograms)
    {
        Assert::That(is_isogram("ab"), Equals(true), ExtraMessage(R"(Incorrect result for input = "ab":)"));
        Assert::That(is_isogram("Ba"), Equals(true), ExtraMessage(R"(Incorrect result for input = "Ba":)"));
        Assert::That(is_isogram("acb"), Equals(true), ExtraMessage(R"(Incorrect result for input = "acb":)"));
        Assert::That(is_isogram("GROWTH"), Equals(true), ExtraMessage(R"(Incorrect result for input = "GROWTH":)"));
        Assert::That(is_isogram("isogram"), Equals(true), ExtraMessage(R"(Incorrect result for input = "isogram":)"));
        Assert::That(is_isogram("Dermatoglyphics"), Equals(true), ExtraMessage(R"(Incorrect result for input = "Dermatoglyphics":)"));
        Assert::That(is_isogram("thumbscrewjapingly"), Equals(true), ExtraMessage(R"(Incorrect result for input = "thumbscrewjapingly":)"));
        Assert::That(is_isogram("acdefghijklmnopqrstuvwxBz"), Equals(true), ExtraMessage(R"(Incorrect result for input = "acdefghijklmnopqrstuvwxBz":)"));
        Assert::That(is_isogram("abcdefghijklmnopqrstuvwxyz"), Equals(true), ExtraMessage(R"(Incorrect result for input = "abcdefghijklmnopqrstuvwxyz":)"));
        Assert::That(is_isogram("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), Equals(true), ExtraMessage(R"(Incorrect result for input = "ABCDEFGHIJKLMNOPQRSTUVWXYZ":)"));
    } 
    It(should_detect_non_isograms)
    {       
        Assert::That(is_isogram("aa"), Equals(false), ExtraMessage(R"(Incorrect result for input = "aa":)"));
        Assert::That(is_isogram("aA"), Equals(false), ExtraMessage(R"(Incorrect result for input = "aA":)"));
        Assert::That(is_isogram("aba"), Equals(false), ExtraMessage(R"(Incorrect result for input = "aba":)"));
        Assert::That(is_isogram("ZzZ"), Equals(false), ExtraMessage(R"(Incorrect result for input = "ZzZ":)"));
        Assert::That(is_isogram("moose"), Equals(false), ExtraMessage(R"(Incorrect result for input = "moose":)"));
        Assert::That(is_isogram("moOse"), Equals(false), ExtraMessage(R"(Incorrect result for input = "moOse":)"));
        Assert::That(is_isogram("uNIQUe"), Equals(false), ExtraMessage(R"(Incorrect result for input = "uNIQUe":)"));
        Assert::That(is_isogram("roboto"), Equals(false), ExtraMessage(R"(Incorrect result for input = "roboto":)"));
        Assert::That(is_isogram("parmesan"), Equals(false), ExtraMessage(R"(Incorrect result for input = "parmesan":)"));
        Assert::That(is_isogram("LIPGLOSS"), Equals(false), ExtraMessage(R"(Incorrect result for input = "LIPGLOSS":)"));
        Assert::That(is_isogram("isIsogram"), Equals(false), ExtraMessage(R"(Incorrect result for input = "isIsogram":)"));
        Assert::That(is_isogram("abcdefghijklmnopqrstuwwxyz"), Equals(false), ExtraMessage(R"(Incorrect result for input = "abcdefghijklmnopqrstuwwxyz":)"));
        Assert::That(is_isogram("abcdefghijklmnopqrstuvwxyzA"), Equals(false), ExtraMessage(R"(Incorrect result for input = "abcdefghijklmnopqrstuvwxyzA":)"));
        Assert::That(is_isogram("ABCDEFGHIJKLMNOPQRSTUVWXYZh"), Equals(false), ExtraMessage(R"(Incorrect result for input = "ABCDEFGHIJKLMNOPQRSTUVWXYZh":)"));
    }
};