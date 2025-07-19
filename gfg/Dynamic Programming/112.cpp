#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
✅ Problem: Longest Common Subsequence

Given two strings s1 and s2, return the length of their longest common subsequence (LCS).

A subsequence is a sequence that can be derived by deleting some (or no) characters from a string,
without changing the order of the remaining characters.

🔸 Examples:

Input: s1 = "ABCDGH", s2 = "AEDFHR"
Output: 3
Explanation: The LCS is "ADH"

Input: s1 = "ABC", s2 = "AC"
Output: 2
Explanation: The LCS is "AC"

🔸 Constraints:
1 <= s1.size(), s2.size() <= 10^3
s1 and s2 contain only uppercase English letters.
*/

/*
✅ Approach: Dynamic Programming

We define a 2D DP table where:
- dp[i][j] = LCS length of s1[0..i-1] and s2[0..j-1]

🔹 If s1[i-1] == s2[j-1]:
    dp[i][j] = 1 + dp[i-1][j-1]
🔹 Else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

The final answer is in dp[m][n]
*/

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();

        // DP table initialized to 0
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1]; // characters match
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // skip one character
                }
            }
        }

        return dp[m][n]; // Final result
    }
};

int main() {
    // Sample input
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";

    Solution sol;
    int result = sol.lcs(s1, s2);

    cout << "Length of Longest Common Subsequence: " << result << endl;
    return 0;
}
