/*
  ✅ Question: Longest Palindromic Subsequence

  Given a string `s`, return the length of the longest palindromic subsequence in it.

  - A subsequence is a sequence that can be derived by deleting some or no characters without changing the order.
  - A palindromic subsequence is one that reads the same forwards and backwards.

  Examples:
    Input: s = "bbabcbcab"
    Output: 7
    Explanation: "babcbab" is the longest palindromic subsequence.

    Input: s = "abcd"
    Output: 1
    Explanation: All characters are palindromes of length 1.

    Input: s = "agbdba"
    Output: 5
    Explanation: "abdba" is the longest palindromic subsequence.

  Constraints:
    1 <= s.length <= 1000
    s contains only lowercase English letters.
*/

/*
  🧠 Approach:

  We use Dynamic Programming (DP).
  Let dp[i][j] represent the length of the longest palindromic subsequence in s[i...j].

  - If s[i] == s[j], then dp[i][j] = 2 + dp[i+1][j-1]
  - Else, dp[i][j] = max(dp[i+1][j], dp[i][j-1])

  We build the DP table from shorter substrings to longer substrings.
*/

#include <iostream>
#include <vector>
using namespace std;

// Class that contains the function to solve the problem
class Solution {
  public:
    int longestPalinSubseq(string &s) {
        int n = s.size();

        // Create a 2D DP table initialized to 0
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Every character is a palindrome of length 1
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        // Fill the table for substrings of length 2 to n
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len == 2)
                        dp[i][j] = 2; // Two matching characters
                    else
                        dp[i][j] = 2 + dp[i + 1][j - 1]; // Match + inner substring
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // Skip one side
                }
            }
        }

        // Final answer for the whole string
        return dp[0][n - 1];
    }
};

// Main function to test the code
int main() {
    Solution sol;

    string s1 = "bbabcbcab";
    string s2 = "abcd";
    string s3 = "agbdba";

    cout << "Input: " << s1 << "\nOutput: " << sol.longestPalinSubseq(s1) << "\n\n";
    cout << "Input: " << s2 << "\nOutput: " << sol.longestPalinSubseq(s2) << "\n\n";
    cout << "Input: " << s3 << "\nOutput: " << sol.longestPalinSubseq(s3) << "\n\n";

    return 0;
}
