/*
📌 Question:
You are given an array `arr[]` of non-negative integers of size `n`.  
Find the maximum possible XOR between any two numbers in the array.

Example 1:
Input: arr[] = [25, 10, 2, 8, 5, 3]
Output: 28
Explanation: Maximum possible XOR = 5 ^ 25 = 28

Example 2:
Input: arr[] = [1, 2, 3, 4, 5, 6, 7]
Output: 7
Explanation: Maximum possible XOR = 1 ^ 6 = 7

Constraints:
- 2 ≤ n ≤ 5 * 10^4
- 1 ≤ arr[i] ≤ 10^6
*/

/*
📌 Approach:
1. Naive method: Check all pairs and compute XOR → O(n²), too slow.
2. Optimized method:
   - Build a binary Trie of numbers using their bits.
   - Each node has 2 children (0 and 1).
   - For each number, traverse the trie to maximize XOR (prefer opposite bit).
   - Complexity: O(n log M), where M = max number in array (~20 bits).
*/

/*
📌 Algorithm:
1. Build a Trie (bitwise tree).
2. Insert each number bit by bit (MSB → LSB).
3. For each number:
   - Traverse trie, always trying to go to opposite bit (maximize XOR).
   - If not available, go to same bit.
   - Compute XOR result.
4. Track maximum XOR found.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct TrieNode {
        TrieNode* children[2];
        TrieNode() {
            children[0] = children[1] = nullptr;
        }
    };
    
    class Trie {
        TrieNode* root;
    public:
        Trie() { root = new TrieNode(); }
        
        // Insert number into trie
        void insert(int num) {
            TrieNode* node = root;
            for (int i = 20; i >= 0; i--) {  // 21 bits enough for 1e6
                int bit = (num >> i) & 1;
                if (!node->children[bit]) 
                    node->children[bit] = new TrieNode();
                node = node->children[bit];
            }
        }
        
        // Get maximum XOR possible with this num
        int getMaxXor(int num) {
            TrieNode* node = root;
            int maxXor = 0;
            for (int i = 20; i >= 0; i--) {
                int bit = (num >> i) & 1;
                int opp = 1 - bit;
                if (node->children[opp]) {
                    maxXor |= (1 << i); // set this bit in result
                    node = node->children[opp];
                } else {
                    node = node->children[bit];
                }
            }
            return maxXor;
        }
    };
    
public:
    int maxXor(vector<int> &arr) {
        Trie trie;
        for (int num : arr) trie.insert(num); // build trie
        int ans = 0;
        for (int num : arr) {
            ans = max(ans, trie.getMaxXor(num));
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {25, 10, 2, 8, 5, 3};
    Solution ob;
    cout << "Maximum XOR: " << ob.maxXor(arr) << endl;  // Output: 28
    
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7};
    cout << "Maximum XOR: " << ob.maxXor(arr2) << endl; // Output: 7
    
    return 0;
}

/*
📌 Code Explanation:
1. TrieNode → each node has 2 children (0 and 1).
2. insert(num) → stores bits of number in trie from MSB to LSB.
3. getMaxXor(num) → for each bit, try to go to opposite bit (maximize XOR).
4. maxXor(arr) → 
   - Insert all numbers.
   - For each number, calculate max XOR with trie.
   - Keep track of maximum result.
5. main() → runs test cases.
*/
