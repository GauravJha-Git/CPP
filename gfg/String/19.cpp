// Min Chars to Add for Palindrome
// Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

// Note: A palindrome string is a sequence of characters that reads the same forward and backward.

// Examples:

// Input: s = "abc"
// Output: 2
// Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc"

// Approach Recap:
// We can use the KMP algorithm's LPS (Longest Prefix Suffix) technique to efficiently find the longest palindromic prefix of the string and then calculate the number of characters to be added.

// Steps:
// Reverse the given string s to form rev_s.

// Concatenate s and rev_s with a special delimiter, such as #, in between. This will help distinguish the two parts.

// Compute the LPS array for this concatenated string.

// The result will be the difference between the length of the original string and the longest palindromic prefix (which can be found in the last value of the LPS array).

// code - 
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to compute the LPS (Longest Prefix Suffix) array
    vector<int> computeLPS(string& s) {
        int n = s.size();
        vector<int> lps(n, 0);
        int len = 0; // Length of the previous longest prefix suffix
        int i = 1;
        
        while(i < n) {
            if(s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if(len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    
    // Function to find the minimum characters to add at the front to make it palindrome
    int minChar(string& s) {
        // Step 1: Reverse the string
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        // Step 2: Concatenate the original string, a delimiter and the reversed string
        string combined = s + "#" + rev_s;
        
        // Step 3: Compute the LPS array for the concatenated string
        vector<int> lps = computeLPS(combined);
        
        // Step 4: The result is the difference between the original length and the LPS value
        return s.size() - lps.back();
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;
    }
    return 0;
}
