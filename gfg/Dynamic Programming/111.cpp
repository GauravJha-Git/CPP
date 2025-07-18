/*
🔶 PROBLEM: Longest String Chain

You are given an array of words where each word consists of lowercase English letters.

A word A is a predecessor of word B if and only if we can insert exactly one letter anywhere in word A without changing the order of the other characters to make it equal to B.
For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".

A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1,
where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on.

A single word is trivially a word chain with k = 1.

Return the length of the longest possible word chain with words chosen from the given list of words in any order.

🔸 Examples:

Input: words[] = {"ba", "b", "a", "bca", "bda", "bdca"}
Output: 4
Explanation: One of the longest word chains is ["a", "ba", "bda", "bdca"]

Input: words[] = {"abc", "a", "ab"}
Output: 3
Explanation: The longest chain is ["a", "ab", "abc"]

Input: words[] = {"abcd", "dbqca"}
Output: 1
Explanation: Only single words are valid chains.

🔸 Constraints:
- 1 <= words.length <= 10^4
- 1 <= words[i].length <= 10
- words[i] consists of lowercase English letters only
*/

/*
💡 APPROACH:

1. Sort the list of words by their lengths. This helps build longer words from shorter ones.
2. Use a hash map to store the longest chain length ending at each word.
3. For every word, generate all possible predecessors by removing one character at every position.
4. If a predecessor exists in the map, update the current word’s max chain length.
5. Keep track of the maximum chain length found.

⏱ Time Complexity: O(N × L²), where N is number of words and L is max word length
📦 Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Step 1: Sort words by length
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;
        int maxLength = 1;

        for (const string& word : words) {
            dp[word] = 1;  // Single word is a chain of length 1

            // Generate all possible predecessors by removing one character
            for (int i = 0; i < word.size(); ++i) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(prev) != dp.end()) {
                    dp[word] = max(dp[word], dp[prev] + 1);
                }
            }

            maxLength = max(maxLength, dp[word]);
        }

        return maxLength;
    }
};

// 🔽 MAIN FUNCTION TO TEST
int main() {
    Solution sol;

    vector<string> words1 = {"ba", "b", "a", "bca", "bda", "bdca"};
    cout << "Test Case 1: " << sol.longestStringChain(words1) << endl; // Output: 4

    vector<string> words2 = {"abc", "a", "ab"};
    cout << "Test Case 2: " << sol.longestStringChain(words2) << endl; // Output: 3

    vector<string> words3 = {"abcd", "dbqca"};
    cout << "Test Case 3: " << sol.longestStringChain(words3) << endl; // Output: 1

    return 0;
}

/*
🔍 CODE EXPLANATION:

- We sort the words so that we always process smaller words first.
- We maintain a map `dp[word]` which stores the longest chain ending at that word.
- For each word, we generate all possible valid predecessors by deleting one letter at every index.
- If the predecessor exists in `dp`, we update the current word’s chain length.
- At the end, we return the maximum chain length found among all words.
*/
