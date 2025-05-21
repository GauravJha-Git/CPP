/*
📌 Question:
Max Pairs

Given a string `s` and an integer `m`, form as many good pairs of characters from `s` as possible.

A good pair of characters is:
1. A pair of identical characters, or
2. A pair of different characters where the sum of their ASCII values is a multiple of `m`.

Each character can be used at most once in pairing.

Return the maximum number of such good pairs that can be formed.

---

💡 Approach:
1. Count frequency of each character.
2. Form all possible identical pairs first.
3. Track used characters.
4. Try forming pairs with different characters where (ASCII(a) + ASCII(b)) % m == 0.
5. Use characters only if they are still available.

---

🧪 Special Concepts Used:
- unordered_map<char, int>: For counting and tracking.
- vector<char>: To iterate over character pairs.
- ASCII values of characters: Used in sum checking.
- min(a, b): To make max number of cross pairs from remaining chars.

---

💻 Code:
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
  public:
    long long countValidPairs(string& s, int m) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        unordered_map<char, int> used;
        long long pairs = 0;

        // Count identical character pairs
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            char ch = it->first;
            int count = it->second;
            int same = count / 2;
            pairs += same;
            used[ch] += same * 2;
        }

        vector<char> chars;
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            chars.push_back(it->first);
        }

        int n = chars.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                char a = chars[i];
                char b = chars[j];
                int sum = a + b;

                if (sum % m == 0) {
                    int leftA = freq[a] - used[a];
                    int leftB = freq[b] - used[b];
                    int make = min(leftA, leftB);

                    pairs += make;
                    used[a] += make;
                    used[b] += make;
                }
            }
        }

        return pairs;
    }
};

/*
🧠 Code Explanation:
- First we count how many times each character appears.
- We form all possible pairs of the same character (like "aa", "bb").
- Then we look at all combinations of different characters.
- If their ASCII sum is divisible by `m`, and they are still unused, we form pairs.
- We return the total number of good pairs.

⚠️ Confusing Parts Clarified:
- char a + char b: This adds their ASCII values. Totally valid!
- used[ch] += same * 2: Two characters are used per identical pair.
- freq[a] - used[a]: Tells us how many characters are still free to pair.
- chars.push_back(it->first): Creates a list of all unique characters for pairing.
*/

int main() {
    Solution sol;

    string s = "aabbcc";
    int m = 195; // ASCII of 'a' + 'b' = 97 + 98 = 195 (Good pair)
    cout << "Max good pairs: " << sol.countValidPairs(s, m) << endl;

    // Another test case
    string t = "abcxyz";
    int m2 = 200;
    cout << "Max good pairs: " << sol.countValidPairs(t, m2) << endl;

    return 0;
}
