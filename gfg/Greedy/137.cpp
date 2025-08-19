/*
📌 Problem: Maximize Partitions in a String
Difficulty: Easy

Given a string s of lowercase English alphabets, your task is to return the 
maximum number of substrings formed, after possible partitions (probably zero) 
of s such that no two substrings have a common character.

---------------------------------------------------
Examples:

Input: s = "acbbcc"
Output: 2
Explanation: "a" and "cbbcc" are two substrings that do not share any 
characters between them.

Input: s = "ababcbacadefegdehijhklij"
Output: 3
Explanation: Partitioning at index 8 and 15 gives substrings: 
“ababcbaca”, “defegde”, “hijhklij”.

Input: s = "aaa"
Output: 1
Explanation: All characters are same, so only one substring.
---------------------------------------------------

🔑 Approach (Greedy + Last Occurrence)
1. Find last occurrence of every character in the string.
2. Traverse the string and maintain the "boundary" = farthest last occurrence 
   of characters seen so far.
3. If current index == boundary → cut (partition) here.
4. Count total cuts → maximum partitions.

---------------------------------------------------
🔎 Dry Run for "acbbcc":
- Last indices: a:0, b:3, c:5
- Traverse:
  i=0 (a) → boundary=0 → cut → "a"
  i=1..5 → boundary=5 → cut → "cbbcc"
- Total partitions = 2 ✅

---------------------------------------------------
⏱ Complexity:
- Time: O(n)
- Space: O(26) ~ O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxPartitions(string &s) {
        int n = s.size();
        vector<int> last(26, -1);
        
        // Step 1: Store last occurrence of each character
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }
        
        int partitions = 0, boundary = 0;
        
        // Step 2: Traverse and cut partitions greedily
        for (int i = 0; i < n; i++) {
            boundary = max(boundary, last[s[i] - 'a']);
            
            // Step 3: If we reach the boundary → cut here
            if (i == boundary) {
                partitions++;
            }
        }
        
        return partitions;
    }
};

// 🚀 Driver code
int main() {
    Solution sol;
    
    string s1 = "acbbcc";
    cout << sol.maxPartitions(s1) << endl; // Output: 2
    
    string s2 = "ababcbacadefegdehijhklij";
    cout << sol.maxPartitions(s2) << endl; // Output: 3
    
    string s3 = "aaa";
    cout << sol.maxPartitions(s3) << endl; // Output: 1
    
    return 0;
}
