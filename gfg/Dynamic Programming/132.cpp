/*
Word Break Problem
==================
You are given:
- A string s
- A list dictionary[] containing valid words.

Your task is to determine whether s can be formed by concatenating
one or more words from dictionary[].
A word can be used multiple times and in any order.

Example 1:
Input:
s = "ilike"
dictionary[] = ["i", "like", "gfg"]
Output: true
Explanation: "i like" is a valid breakdown.

Example 2:
Input:
s = "ilikegfg"
dictionary[] = ["i", "like", "man", "india", "gfg"]
Output: true
Explanation: "i like gfg" is valid.

Example 3:
Input:
s = "ilikemangoes"
dictionary[] = ["i", "like", "man", "india", "gfg"]
Output: false
Explanation: Cannot form using given dictionary words.

Constraints:
1 ≤ s.size() ≤ 3000
1 ≤ dictionary.size() ≤ 1000
1 ≤ dictionary[i].size() ≤ 100

--------------------------------------------------
Approach:
We solve this using Dynamic Programming.

1. State definition:
   Let dp[i] = true if the substring s[0...i-1] can be formed from dictionary words.

2. Base case:
   dp[0] = true → empty string can be formed trivially.

3. Transition:
   For each index i from 1 to n:
   - Check all split points j from 0 to i-1:
     - If dp[j] is true AND s[j...i-1] exists in dictionary → set dp[i] = true.

4. Result:
   Answer is dp[n] (where n = length of s).

5. Optimization:
   Store dictionary in unordered_set<string> for O(1) lookup.

--------------------------------------------------
Explanation:
We build dp from left to right:
- For each position, we check if there’s a previous position where:
  1. The prefix before it is already valid.
  2. The substring from that position to current is in the dictionary.

If both conditions match, the current position is marked as reachable.

--------------------------------------------------
Code Explanation:
- unordered_set<string> dict: Fast lookup for dictionary words.
- dp vector: dp[i] means s[0..i-1] can be formed using dictionary words.
- Outer loop (i): current substring end.
- Inner loop (j): checks all cut points before i.
- Condition: if prefix is valid (dp[j]) and current word (s.substr(j, i-j)) is in dictionary → mark dp[i] = true.
- Break once a valid cut is found to save time.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Empty string can always be segmented

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break; // Found a valid segmentation
                }
            }
        }
        return dp[n];
    }
};

int main() {
    string s = "ilikegfg";
    vector<string> dictionary = {"i", "like", "man", "india", "gfg"};

    Solution obj;
    if (obj.wordBreak(s, dictionary))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
