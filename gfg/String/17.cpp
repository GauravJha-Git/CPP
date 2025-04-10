// Non Repeating Character
// Given a string s consisting of lowercase English Letters. Return the first non-repeating character in s.
// If there is no non-repeating character, return '$'.
// Note: When you return '$' driver code will output -1.

// Examples:

// Input: s = "geeksforgeeks"
// Output: 'f'
// Explanation: In the given string, 'f' is the first character in the string which does not repeat.

// code-

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    char nonRepeatingChar(string &s) {
        vector<int> freq(26, 0);
        
        // Count frequency of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        
        // Find the first character with frequency 1
        for (char ch : s) {
            if (freq[ch - 'a'] == 1) {
                return ch;
            }
        }
        
        return '$'; // If no non-repeating character
    }
};


int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

