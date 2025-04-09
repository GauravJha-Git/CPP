// Anagram


// Given two strings s1 and s2 consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, "act" and "tac" are an anagram of each other. Strings s1 and s2 can only contain lowercase alphabets.

// Note: You can assume both the strings s1 & s2 are non-empty.

// Examples :

// Input: s1 = "geeks", s2 = "kseeg"
// Output: true
// Explanation: Both the string have same characters with same frequency. So, they are anagrams.

// 🧠 What is an Anagram?
// An anagram is a word or phrase formed by rearranging the letters of another word, using all the original letters exactly once.

// 💡 Example:
// "listen" and "silent" → ✅ Anagrams

// "race" and "care" → ✅ Anagrams

// "hello" and "world" → ❌ Not Anagrams

// Both strings must have:

// The same characters

// With the same frequencies

// But can be in any order

// ✅ Approach
// We will use the frequency counting approach with a fixed-size array of 26 (for all lowercase letters).

// Steps:
// Check lengths of both strings.

// If lengths are different → they can’t be anagrams.

// Create a frequency array of size 26 (for a to z).

// Increment count for each character in s1 and decrement count for each character in s2.

// If all counts in the array are 0, the strings are anagrams.

// code-

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // Function to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Step 1: Check length
        if (s1.length() != s2.length()) return false;

        // Step 2: Create a frequency array for 26 lowercase letters
        int count[26] = {0};

        // Step 3: Count frequencies from both strings
        for (int i = 0; i < s1.length(); i++) {
            count[s1[i] - 'a']++;   // Increment for s1
            count[s2[i] - 'a']--;   // Decrement for s2
        }

        // Step 4: Check if all counts are 0
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }

        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string c, d;
        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
