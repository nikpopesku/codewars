/*
 * PARTITION PROBLEM - 2D Dynamic Programming Solution
 * ===================================================
 *
 * Problem: Find the number of ways to partition a positive integer n
 *         into a sum of positive integers where order doesn't matter.
 *
 * This is also known as the "Partition Function p(n)" in number theory.
 *
 * Examples:
 * p(1) = 1  -> {1}
 * p(2) = 2  -> {1+1, 2}
 * p(3) = 3  -> {1+1+1, 1+2, 3}
 * p(4) = 5  -> {1+1+1+1, 1+1+2, 1+3, 2+2, 4}
 * p(5) = 7  -> {1+1+1+1+1, 1+1+1+2, 1+1+3, 1+2+2, 1+4, 5, 2+3}
 */

#include "../cw_compat.hpp"
#include <vector>
#include <iostream>

using namespace std;
using ull = unsigned long long;

/*
 * ========================================================================
 * FUNCTION: exp_sum_2d (2D Dynamic Programming Approach)
 * ========================================================================
 *
 * ALGORITHM EXPLANATION:
 * =====================
 *
 * We use a 2D DP table where:
 * - dp[i][j] represents the number of ways to partition integer 'i'
 *   using positive integers up to and including 'j'
 *
 * KEY INSIGHTS:
 * ============
 * 1. For any target sum 'i' and maximum part 'j':
 *    - We either DON'T use 'j' in our partition -> dp[i][j-1] ways
 *    - Or we DO use 'j' at least once -> dp[i-j][j] ways
 *
 * 2. This gives us the recurrence relation:
 *    dp[i][j] = dp[i][j-1] + dp[i-j][j]
 *
 * BASE CASES:
 * ==========
 * 1. dp[0][j] = 1 for any j >= 0
 *    - There's exactly one way to partition 0: use no numbers at all
 *
 * 2. dp[i][0] = 0 for any i > 0
 *    - Can't partition a positive number using only positive integers up to 0
 *
 * EXAMPLE WALKTHROUGH for p(4):
 * =============================
 * Let's build the DP table row by row:
 *
 *    j=0  j=1  j=2  j=3  j=4   (maximum allowed part)
 * i=0:  1    1    1    1    1    <- base case: dp[0][j] = 1
 * i=1:  0    1    1    1    1    <- dp[1][1] = dp[1][0] + dp[0][1] = 0 + 1 = 1
 * i=2:  0    1    2    2    2    <- dp[2][2] = dp[2][1] + dp[0][2] = 1 + 1 = 2
 * i=3:  0    1    2    3    3    <- dp[3][3] = dp[3][2] + dp[0][3] = 2 + 1 = 3
 * i=4:  0    1    3    4    5    <- dp[4][4] = dp[4][3] + dp[0][4] = 4 + 1 = 5
 *
 * Final answer: dp[4][4] = 5 partitions:
 * 4, 3+1, 2+2, 2+1+1, 1+1+1+1
 *
 * TIME COMPLEXITY: O(n²)
 * SPACE COMPLEXITY: O(n²)
 */
ull exp_sum_2d(const unsigned int n) {
    cout << "\n=== 2D DP SOLUTION FOR exp_sum(" << n << ") ===" << endl;

    // Edge case: There's exactly 1 way to partition 0 (empty partition)
    if (n == 0) {
        cout << "Base case: exp_sum(0) = 1 (empty partition)" << endl;
        return 1;
    }

    // Create DP table: dp[i][j] = ways to partition i using numbers up to j
    // Table dimensions: (n+1) x (n+1) to include indices 0 through n
    vector<vector<ull>> dp(n + 1, vector<ull>(n + 1, 0));

    cout << "Initializing DP table with dimensions " << (n+1) << "x" << (n+1) << endl;

    // Set base case 1: dp[0][j] = 1 for all j (empty partition for sum 0)
    for (unsigned int j = 0; j <= n; ++j) {
        dp[0][j] = 1;
        cout << "Base case: dp[0][" << j << "] = 1 (one way to partition 0)" << endl;
    }

    // Set base case 2: dp[i][0] = 0 for all i > 0
    // (already initialized to 0, so this is just for clarity)
    cout << "Base case: dp[i][0] = 0 for i > 0 (can't partition positive number with no parts)" << endl;

    // Fill the DP table using our recurrence relation
    cout << "\nBuilding DP table using recurrence: dp[i][j] = dp[i][j-1] + dp[i-j][j]" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    for (unsigned int i = 1; i <= n; ++i) {        // For each target sum i
        for (unsigned int j = 1; j <= n; ++j) {    // For each maximum part j

            if (j > i) {
                // If j > i, we can't use j, so dp[i][j] = dp[i][j-1]
                dp[i][j] = dp[i][j-1];
                cout << "dp[" << i << "][" << j << "] = dp[" << i << "][" << (j-1) << "] = " << dp[i][j]
                     << " (j > i, can't use " << j << ")" << endl;
            } else {
                // Apply recurrence: dp[i][j] = dp[i][j-1] + dp[i-j][j]
                // dp[i][j-1]: partitions that don't use j
                // dp[i-j][j]: partitions that use j at least once
                ull without_j = dp[i][j-1];
                ull with_j = dp[i-j][j];
                dp[i][j] = without_j + with_j;

                cout << "dp[" << i << "][" << j << "] = dp[" << i << "][" << (j-1) << "] + dp["
                     << (i-j) << "][" << j << "] = " << without_j << " + " << with_j
                     << " = " << dp[i][j] << endl;
            }
        }
        cout << "--- Completed row i=" << i << " ---" << endl;
    }

    // Display the final DP table for visualization
    cout << "\nFinal DP Table:" << endl;
    cout << "     ";
    for (unsigned int j = 0; j <= n; ++j) {
        cout << "j=" << j << "    ";
    }
    cout << endl;

    for (unsigned int i = 0; i <= n; ++i) {
        cout << "i=" << i << ": ";
        for (unsigned int j = 0; j <= n; ++j) {
            cout << dp[i][j] << "    ";
        }
        cout << endl;
    }

    ull result = dp[n][n];
    cout << "\nFinal Answer: exp_sum(" << n << ") = dp[" << n << "][" << n << "] = " << result << endl;
    cout << "This means there are " << result << " different ways to partition " << n << endl;

    return result;
}

/*
 * ========================================================================
 * FUNCTION: exp_sum (Original function maintaining compatibility)
 * ========================================================================
 * This function maintains the original interface but uses our 2D DP solution
 */
ull exp_sum(const unsigned int n) {
    return exp_sum_2d(n);
}

/*
 * ========================================================================
 * TEST SUITE - Comprehensive testing of the 2D DP solution
 * ========================================================================
 */
Describe(explosive_sum_2d_tests) {
    It(Basic_Tests) {
        // Test the basic examples from the problem description
        cout << "\n" << string(60, '=') << endl;
        cout << "TESTING BASIC CASES" << endl;
        cout << string(60, '=') << endl;

        Assert::That(exp_sum(1), Equals(1));
        Assert::That(exp_sum(2), Equals(2));
        Assert::That(exp_sum(3), Equals(3));
        Assert::That(exp_sum(4), Equals(5));
        Assert::That(exp_sum(5), Equals(7));
        Assert::That(exp_sum(10), Equals(42));
    }

    It(Explosive_Tests) {
        cout << "\n" << string(60, '=') << endl;
        cout << "TESTING EXPLOSIVE CASES" << endl;
        cout << string(60, '=') << endl;

        // Test the larger explosive examples
        Assert::That(exp_sum(50), Equals(204226));
        Assert::That(exp_sum(80), Equals(15796476));
        Assert::That(exp_sum(100), Equals(190569292));
    }

    It(Edge_Cases) {
        cout << "\n" << string(60, '=') << endl;
        cout << "TESTING EDGE CASES" << endl;
        cout << string(60, '=') << endl;

        // Test edge case for 0
        Assert::That(exp_sum(0), Equals(1));
    }

    It(Verification_Tests) {
        cout << "\n" << string(60, '=') << endl;
        cout << "TESTING VERIFICATION CASES" << endl;
        cout << string(60, '=') << endl;

        // Additional test cases to verify correctness
        Assert::That(exp_sum(6), Equals(11));   // Known partition number
        Assert::That(exp_sum(7), Equals(15));   // Known partition number
        Assert::That(exp_sum(8), Equals(22));   // Known partition number
        Assert::That(exp_sum(9), Equals(30));   // Known partition number
    }
};