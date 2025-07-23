/*
===============================================================
✅ Problem: Count Palindromic Substrings (Length >= 2)
===============================================================

🔷 Description:
Given a string s, count all palindromic substrings present in it.
Only substrings with length >= 2 should be counted.
A substring is palindromic if it reads the same forwards and backwards.

📌 Constraints:
- 2 ≤ s.size() ≤ 1000
- s contains only lowercase English letters

📥 Examples:
Input: s = "abaab"
Output: 3
Explanation: Palindromic substrings: "aba", "aa", "baab"

Input: s = "aaa"
Output: 3
Explanation: "aa", "aa", "aaa"

Input: s = "abbaeae"
Output: 4
Explanation: "bb", "abba", "aea", "eae"

===============================================================
✅ Approach:
===============================================================

We will use **Dynamic Programming** with a 2D table `dp[i][j]`:
- dp[i][j] = true if s[i..j] is a palindrome
- For each possible substring length (from 1 to n), check:
  - If s[i] == s[j] and
    - if len <= 2, it's automatically a palindrome
    - else, check if dp[i+1][j-1] is true

We only count substrings where length >= 2.

📈 Time Complexity: O(n^2)
📦 Space Complexity: O(n^2)

===============================================================
✅ Full Code:
===============================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPS(string &s) {
        int n = s.length();
        int count = 0;

        // Create a DP table initialized with false
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Loop over all substring lengths
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;

                // Check if s[i..j] is a palindrome
                if (s[i] == s[j]) {
                    if (len <= 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // Count only if it's a palindrome of length >= 2
                if (dp[i][j] && len >= 2) {
                    count++;
                }
            }
        }

        return count;
    }
};

// ----------------------------
// ✅ Main Function (For Testing)
// ----------------------------
int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    Solution obj;
    int result = obj.countPS(input);

    cout << "Total palindromic substrings of length >= 2: " << result << endl;
    return 0;
}

/*
===============================================================
✅ Code Explanation:
===============================================================
1. We use a 2D vector `dp` to store whether s[i..j] is a palindrome.
2. We loop over all substring lengths from 1 to n.
3. For each i and j (start and end index), we:
   - Check if s[i] == s[j]
   - If yes, and the length is 2 or less -> it's a palindrome
   - If more than 2, we check if the inner substring s[i+1..j-1] is a palindrome
4. If dp[i][j] is true and length >= 2, we increase the count.
5. Finally, print the total count.
===============================================================
*/
