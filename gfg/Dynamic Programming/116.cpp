/*
===============================
💬 PROBLEM: Edit Distance
===============================

Given two strings s1 and s2. Return the minimum number of operations required to convert s1 to s2.

Allowed operations:
1. Insert a character
2. Remove a character
3. Replace a character

------------------
📥 Examples:
------------------
Input:  s1 = "geek", s2 = "gesek"
Output: 1
Explanation: Insert 's' between 'e' and 'e'

Input:  s1 = "gfg", s2 = "gfg"
Output: 0
Explanation: No operations needed

Input:  s1 = "abcd", s2 = "bcfe"
Output: 3
Explanation: Remove 'a', replace 'd' with 'f', insert 'e'

------------------
📌 Constraints:
------------------
1 ≤ s1.length(), s2.length() ≤ 1000
Both strings are lowercase

===============================
🧠 APPROACH: Dynamic Programming
===============================

Let dp[i][j] be the minimum number of operations to convert first i characters of s1 to first j characters of s2.

If s1[i-1] == s2[j-1], no operation needed:
    dp[i][j] = dp[i-1][j-1]
Else:
    dp[i][j] = 1 + min(
        dp[i-1][j],   // Remove
        dp[i][j-1],   // Insert
        dp[i-1][j-1]  // Replace
    )

Base cases:
- dp[0][j] = j  // insert all characters of s2
- dp[i][0] = i  // remove all characters of s1

Time:  O(m * n)
Space: O(m * n)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) {
                    dp[i][j] = j; // Insert all characters of s2
                } else if (j == 0) {
                    dp[i][j] = i; // Remove all characters of s1
                } else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // Characters match
                } else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],    // Remove
                        dp[i][j - 1],    // Insert
                        dp[i - 1][j - 1] // Replace
                    });
                }
            }
        }

        return dp[m][n];
    }
};

// ==============================
// 🧪 Driver Code to Test
// ==============================
int main() {
    Solution sol;
    string s1, s2;
    
    cout << "Enter first string: ";
    cin >> s1;
    
    cout << "Enter second string: ";
    cin >> s2;

    int result = sol.editDistance(s1, s2);
    cout << "Minimum operations to convert: " << result << endl;

    return 0;
}

/*
===============================
📘 CODE EXPLANATION
===============================
- We define a 2D dp table where dp[i][j] holds the minimum edit distance between:
    s1[0...(i-1)] and s2[0...(j-1)]
- We fill this table from bottom up.
- If characters match → just carry the previous value.
- Otherwise, we compute the minimum from:
    Insert, Remove, and Replace operations.
- Finally, dp[m][n] gives the total minimum edit distance.
*/
