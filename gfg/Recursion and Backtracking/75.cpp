/*
Permutations of a String
Difficulty: Medium  |  Accuracy: 34.65%  |  Submissions: 312K+  |  Points: 4

Question:
Given a string s (may contain duplicate uppercase characters), return all unique permutations of the string in any order.

Examples:
  Input:  s = "ABC"
  Output: ["ABC","ACB","BAC","BCA","CAB","CBA"]

  Input:  s = "AAB"
  Output: ["AAB","ABA","BAA"]

  Input:  s = "AAA"
  Output: ["AAA"]

Constraints:
  1 <= s.length() <= 9
  s contains only uppercase English letters (A–Z)

Approach:
  1. Sort the string to group duplicates.
  2. Use backtracking to build permutations one character at a time.
  3. Track used characters with a boolean visited[] array.
  4. Skip duplicate choices by checking if the current character equals the previous
     and the previous was not used in this recursion level.
  5. Collect completed permutations in a result vector.

Explanation:
  - Sorting ensures duplicates are adjacent.
  - visited[i] marks if s[i] is already in the current permutation.
  - The skip condition (i>0 && s[i]==s[i-1] && !visited[i-1]) prevents generating
    the same permutation multiple times.
  - Backtracking explores all valid arrangements, adding and removing characters
    as it recurses.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(string &s, vector<bool> &visited, string &current, vector<string> &result) {
        if (current.size() == s.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (visited[i]) continue;
            // Skip duplicate characters
            if (i > 0 && s[i] == s[i - 1] && !visited[i - 1]) continue;

            visited[i] = true;
            current.push_back(s[i]);
            backtrack(s, visited, current, result);
            current.pop_back();
            visited[i] = false;
        }
    }

    vector<string> findPermutation(string &s) {
        vector<string> result;
        sort(s.begin(), s.end());         // Sort to handle duplicates
        vector<bool> visited(s.size());    // All initialized to false
        string current;
        backtrack(s, visited, current, result);
        return result;
    }
};

// Code Explanation:
// - sort(s.begin(), s.end()): Groups duplicate letters.
// - vector<bool> visited: Tracks which indices are used.
// - Skip logic prevents reusing the same character arrangement.
// - backtrack() builds each permutation recursively.

int main() {
    Solution sol;
    string s;
    cout << "Enter string: ";
    cin >> s;

    vector<string> permutations = sol.findPermutation(s);
    cout << "Unique permutations (" << permutations.size() << "):\n";
    for (auto &perm : permutations) {
        cout << perm << '\n';
    }
    return 0;
}
