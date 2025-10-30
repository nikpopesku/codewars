#include <string>
#include <stack>

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
