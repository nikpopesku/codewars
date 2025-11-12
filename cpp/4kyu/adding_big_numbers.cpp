#include "../cw_compat.hpp"
#include <string>

using namespace std;


string add(const string &a, const string &b) {
    string response;
    int index_a = a.size() - 1;
    int index_b = b.size() - 1;
    int previous_number = 0;

    while (index_a >= 0 || index_b >= 0) {
        int num_a = index_a >= 0 ? a[index_a] - '0' : 0;
        int num_b = index_b >= 0 ? b[index_b] - '0' : 0;

        const int current_sum = num_a + num_b + previous_number;
        response += to_string(current_sum % 10);
        previous_number = current_sum / 10;
        --index_a;
        --index_b;
    }

    reverse(response.begin(), response.end());

    return response;
}

Describe(Sample_Tests) {
    It(Tests) {
        Assert::That(add("123", "456"), Equals("579"));
        Assert::That(add("0", "0"), Equals("0"));
        // Assert::That(add("99", "2"), Equals("101"));
        // Assert::That(add("10", "35679"), Equals("35689"));
        // Assert::That(add("", "5"), Equals("5"));
        // Assert::That(add("192", ""), Equals("192"));
        // Assert::That(add("9999", "1111"), Equals("11110"));
    }
};
