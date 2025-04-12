// Search Pattern (KMP-Algorithm)
// Given two strings, one is a text string txt and the other is a pattern string pat. The task is to print the indexes of all the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices. 
// Note: Return an empty list in case of no occurrences of pattern.

// Examples :

// Input: txt = "abcab", pat = "ab"
// Output: [0, 3]
// Explanation: The string "ab" occurs twice in txt, one starts at index 0 and the other at index 3. 

// 1. Problem Understanding:
// Given a text string (txt) and a pattern string (pat), we need to find all the occurrences of the pattern in the text using efficient pattern matching.

// We want to return the indices (0-based) where the pattern occurs in the text.

// 2. KMP Algorithm Overview:
// The KMP algorithm is an efficient string matching algorithm that avoids re-checking characters that have already been matched. It uses a preprocessing step to build an array (called the LPS array, Longest Prefix Suffix) which helps us skip unnecessary comparisons during the actual matching phase.

// Key Components:
// LPS (Longest Prefix Suffix) Array:

// The LPS array tells us how much we can skip ahead in the pattern when a mismatch occurs.

// It’s built during the preprocessing phase by checking the longest prefix which is also a suffix for each substring of the pattern.

// Pattern Matching:

// Once the LPS array is built, we start comparing the pattern against the text.

// We use the LPS array to avoid unnecessary re-comparisons of characters.

// 3. Detailed Algorithm:
// Step 1: Preprocessing Phase (Building LPS Array)
// LPS Array Construction:

// The LPS array helps us determine how much we can safely skip forward when a mismatch occurs. It essentially tracks the length of the longest proper prefix of the pattern that is also a suffix.

// Step 2: Matching Phase
// We iterate through the text while simultaneously comparing it with the pattern.

// If a match is found, the index is recorded.

// In case of a mismatch, the LPS array tells us how much we can shift the pattern without losing the matches already found.

// 4. Algorithm in Detail:
// Compute the LPS Array:

// We iterate through the pattern and compute the LPS array. The length of the longest prefix that’s also a suffix is stored for each position.

// Search the Pattern in Text:

// Compare the pattern to the text using the LPS array to skip unnecessary comparisons when mismatches occur.

// If the full pattern is found, record the starting index.

// 5. Time Complexity:
// Preprocessing Phase (LPS computation): O(m), where m is the length of the pattern.

// Matching Phase: O(n), where n is the length of the text. Thus, the overall time complexity is O(n + m), which is much faster than brute-force methods (O(n*m)).

// code -
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to compute the LPS array
    vector<int> computeLPS(string& pat) {
        int m = pat.size();
        vector<int> lps(m, 0); // Initialize LPS array with 0
        int len = 0;  // Length of the previous longest prefix suffix
        int i = 1;

        // Build the LPS array
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];  // Revert to the previous longest prefix suffix
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    // Function to search the pattern in the text
    vector<int> search(string& pat, string& txt) {
        vector<int> res;  // To store result
        int n = txt.size();
        int m = pat.size();
        
        // Compute LPS array for the pattern
        vector<int> lps = computeLPS(pat);

        int i = 0, j = 0;
        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            // If pattern is found
            if (j == m) {
                res.push_back(i - j);  // Store the index of the match
                j = lps[j - 1];  // Get the new j from LPS array
            } 
            // Mismatch after j matches
            else if (i < n && txt[i] != pat[j]) {
                if (j != 0) {
                    j = lps[j - 1];  // Skip unnecessary comparisons using the LPS array
                } else {
                    i++;  // Move the text index forward
                }
            }
        }

        return res;
    }
};


int main() {
    int t;
    cin >> t;  // Read number of test cases
    while (t--) {
        string S, pat;
        cin >> S >> pat;  // Read text and pattern
        Solution ob;
        vector<int> res = ob.search(pat, S);  // Call the search function
        if (res.size() == 0)
            cout << "[]" << endl;  // No occurrences
        else {
            for (int i : res)
                cout << i << " ";  // Print all the occurrences
            cout << endl;
        }
    }
    return 0;
}
