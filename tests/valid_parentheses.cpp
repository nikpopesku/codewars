#include <string>

bool validParentheses(const std::string& str);

// TODO: Replace examples and use TDD by writing your own tests

Describe(SampleTests)
{
    It(ValidCases)
    {
        dotest("()",                 true);
        dotest("((()))",             true);
        dotest("()()()",             true);
        dotest("(()())()",           true);
        dotest("()(())((()))(())()", true);
    }

    It(EmptyString) {
        dotest("", true);
    }

    It(InvalidCases) {
        dotest(")(",     false);
        dotest("()()(",  false);
        dotest("((())",  false);
        dotest("())(()", false);
        dotest(")()",    false);
        dotest(")",      false);
    }

    private:
    void dotest(const std::string& str, bool expected) {
        bool actual = validParentheses(str);
        auto msg    = ExtraMessage("Incorrect answer for input = \"" + str + "\"");
        Assert::That(actual, Equals(expected), msg);
    }
};