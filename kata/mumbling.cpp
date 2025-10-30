#include <string>

using namespace std;

class Accumul {
public:
    static std::string accum(const std::string &s) {
        string response;
        int counter = 1;

        for (const auto c: s) {
            for (int i = 0; i < counter; ++i) {
                response += i == 0 ? toupper(c) : tolower(c);
            }

            if (counter < static_cast<int>(s.size())) {
                response += '-';
            }

            ++counter;
        }

        return response;
    }
};
