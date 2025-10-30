#include <string>

bool validParentheses(const std::string& str);
#include "cw_compat.hpp"

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

};