#include <string>
#include <stack>
#include <bits/stdc++.h>


using namespace std;

int square_digits(int num) {
    // Handle zero explicitly to avoid converting an empty string with stoi
    if (num == 0) return 0;

    stack<string> s;
    string response;

    while (num > 0) {
        const int digit = num % 10;
        num /= 10;

        s.push(to_string(digit * digit));
    }

    while (!s.empty()) {
        response += s.top();
        s.pop();
    }

    return stoi(response);
}
