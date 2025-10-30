#include <string>
#include <stack>

using namespace std;

bool validParentheses(const std::string& str) {
    std::stack s;

    for (auto &c: str) {
        if (c == '(') {
            s.push_back(c);
        } else {
            if (s.empty()) {
                return false;
            }

            s.pop();
        }
    }
}