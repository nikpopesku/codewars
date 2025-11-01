#define CW_BOOL_PREDICATE_FUNC validParentheses
#include <string>
bool validParentheses(const std::string &str);
#include <stack>
#include "cw_compat.hpp"
using namespace std;

bool validParentheses(const std::string &str) {
    stack<char> s;

    for (auto &c: str) {
        if (c == '(') {
            s.push(c);
        } else {
            if (s.empty()) {
                return false;
            }

            s.pop();
        }
    }

    return s.empty();
}

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