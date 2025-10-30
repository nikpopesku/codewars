#include <string>
#include <set>

using namespace std;

bool is_isogram(const std::string& str)
{
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