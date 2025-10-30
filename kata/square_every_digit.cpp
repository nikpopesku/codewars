#include <string>
#include <bits/stdc++.h>


using namespace std;

int square_digits(int num) {
    string response;

    while (num > 0) {
        const int digit = num % 10;
        num /= 10;

        response += to_string(digit * digit);
    }

    reverse(response.begin(), response.end());

    return stoi(response);
}
