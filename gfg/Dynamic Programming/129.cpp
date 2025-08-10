/*
===========================
 Question: Total Decoding Messages
===========================
You are given a string `digits` containing only characters '0'–'9'.
It represents an encoded message using the mapping:
    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26

Your task is to count the total number of ways to decode the message.

---------------------------
Examples:
---------------------------
Input: digits = "123"
Output: 3
Explanation:
    "123" can be decoded as:
        "ABC"  (1 2 3)
        "LC"   (12 3)
        "AW"   (1 23)

Input: digits = "90"
Output: 0
Explanation:
    "90" is invalid because '0' cannot be decoded alone,
    and 90 is not in the range 10–26.

Input: digits = "05"
Output: 0
Explanation:
    Leading zero makes it invalid.

---------------------------
Constraints:
1 ≤ digits.size() ≤ 10^3

===========================
 Approach:
===========================
We solve this with Dynamic Programming:
1. Let dp[i] = number of ways to decode the first i characters.
2. Initialization:
   - dp[0] = 1 → empty string has 1 way.
   - dp[1] = 1 if first character is not '0', else 0.
3. For each position i from 2 to n:
   - If digits[i-1] != '0' → Add dp[i-1] (single digit decode).
   - If two-digit number digits[i-2..i-1] is between 10 and 26 → Add dp[i-2] (two-digit decode).
4. Invalid zeros (like "30", "05") contribute no ways.

Time Complexity: O(n)
Space Complexity: O(n) (can be optimized to O(1))

===========================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(string &digits) {
        int n = digits.size();
        if (n == 0 || digits[0] == '0') return 0;

        vector<int> dp(n + 1, 0);
        dp[0] = 1; // empty string
        dp[1] = 1; // first char valid (not '0')

        for (int i = 2; i <= n; i++) {
            // Single digit check
            if (digits[i - 1] != '0')
                dp[i] += dp[i - 1];

            // Two digit check
            int twoDigit = (digits[i - 2] - '0') * 10 + (digits[i - 1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string digits;
    cin >> digits;

    Solution obj;
    cout << obj.countWays(digits) << "\n";

    return 0;
}

/*
===========================
 Code Explanation:
===========================
- dp[0] = 1 → one way to decode empty string.
- dp[1] = 1 if first char != '0', else 0.
- Loop from i = 2:
  - If last digit != '0', add dp[i-1] (single digit decode).
  - If last two digits form number in [10, 26], add dp[i-2] (two digit decode).
- dp[n] → total ways to decode the entire string.
*/
