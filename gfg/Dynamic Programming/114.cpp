/*
🔴 Problem: Longest Palindromic Substring
Difficulty: Medium

Given a string s, your task is to find the longest palindromic substring within s.

A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s).

A palindrome is a string that reads the same forward and backward.
More formally, s is a palindrome if reverse(s) == s.

Note: If there are multiple palindromic substrings with the same length,
return the first occurrence of the longest palindromic substring from left to right.

Examples:
----------
Input: s = "forgeeksskeegfor"
Output: "geeksskeeg"

Input: s = "Geeks"
Output: "ee"

Input: s = "abc"
Output: "a"

Constraints:
------------
1 ≤ s.size() ≤ 1000
s consists of only lowercase English letters.

--------------------------------------------------------------------

🔷 Approach: Expand Around Center

We check every character (and gap between characters) as a center of a possible palindrome.
From that center, we expand outwards and check how far the palindrome extends.
We do this for both:
- Odd length palindromes (center at i)
- Even length palindromes (center between i and i+1)

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string &s) {
        int n = s.size();
        if (n <= 1) return s;

        int start = 0, maxLen = 1;

        // Lambda function to expand around center
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }
        };

        // Check all centers
        for (int i = 0; i < n; i++) {
            expand(i, i);       // Odd length
            expand(i, i + 1);   // Even length
        }

        return s.substr(start, maxLen);
    }
};

// 🔹 Main function to test the code
int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;

    Solution obj;
    string result = obj.longestPalindrome(str);
    
    cout << "Longest Palindromic Substring: " << result << endl;
    return 0;
}

/*
📌 Code Explanation:
--------------------
- We define a helper lambda `expand(left, right)` that tries to expand outwards while the substring is a palindrome.
- We call it twice for each index:
   1. `expand(i, i)` – for odd length palindromes
   2. `expand(i, i+1)` – for even length palindromes
- If the length of the current palindrome is greater than maxLen, update `start` and `maxLen`.
- Finally, return the substring using `substr(start, maxLen)`.

✅ Test Input: forgeeksskeegfor
✅ Output: geeksskeeg
*/
