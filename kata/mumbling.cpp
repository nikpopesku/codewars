#include <string>

using namespace std;

class Accumul {
public:
    static std::string accum(const std::string &s) {
        string response;
        int counter = 1;

        for (auto c: s) {
            for (int i = 0; i < counter; ++i) {
                if (i == 0) {
                    response += toupper(c);
                    continue;
                }

                response += tolower(c);
            }

            if (counter < static_cast<int>(s.size())) {
                response += '-';
            }

            ++counter;
        }

        return response;
    }
};
