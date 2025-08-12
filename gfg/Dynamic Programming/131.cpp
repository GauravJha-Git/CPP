/*
Question:
----------
You are given a boolean expression s containing:
    'T' -> True
    'F' -> False
    '&' -> boolean AND
    '|' -> boolean OR
    '^' -> boolean XOR

Count the number of ways we can parenthesize the expression so that the value evaluates to True.

Examples:
----------
Input: s = "T|T&F^T"
Output: 4
Explanation: The expression can be parenthesized to True in 4 ways:
((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T), (T|((T&F)^T))

Input: s = "T^F|F"
Output: 2
Explanation: Two ways:
((T^F)|F), (T^(F|F))

Constraints:
-------------
1 ≤ |s| ≤ 100
Answer fits in 32-bit integer.


Approach:
----------
We use Dynamic Programming + Recursion with Memoization.

1. Define solve(i, j, isTrue) → Number of ways to evaluate substring s[i..j] to True (if isTrue=1) or False (if isTrue=0).

2. Base cases:
   - If i > j: return 0
   - If i == j:
       if isTrue: return 1 if s[i] == 'T'
       else:      return 1 if s[i] == 'F'

3. Recurrence:
   - For each operator position k between i and j:
       - Calculate:
           lt = ways left part True
           lf = ways left part False
           rt = ways right part True
           rf = ways right part False
       - Combine results according to truth table of operator.

4. Memoization:
   - Store results in dp[i][j][isTrue] to avoid recomputation.

5. Final answer:
   - solve(0, n-1, 1)

Truth Tables:
-------------
Operator '&':
  True:  lt * rt
  False: lt*rf + lf*rt + lf*rf

Operator '|':
  True:  lt*rt + lt*rf + lf*rt
  False: lf*rf

Operator '^':
  True:  lt*rf + lf*rt
  False: lt*rt + lf*rf
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[105][105][2];
    
    int solve(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0;
        
        if (i == j) {
            if (isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        int ways = 0;
        for (int k = i + 1; k <= j - 1; k += 2) { // operators at odd positions
            char op = s[k];
            
            int lt = solve(s, i, k - 1, true);
            int lf = solve(s, i, k - 1, false);
            int rt = solve(s, k + 1, j, true);
            int rf = solve(s, k + 1, j, false);
            
            if (op == '&') {
                if (isTrue) ways += lt * rt;
                else ways += lt * rf + lf * rt + lf * rf;
            }
            else if (op == '|') {
                if (isTrue) ways += lt * rt + lt * rf + lf * rt;
                else ways += lf * rf;
            }
            else if (op == '^') {
                if (isTrue) ways += lt * rf + lf * rt;
                else ways += lt * rt + lf * rf;
            }
        }
        
        return dp[i][j][isTrue] = ways;
    }
    
    int countWays(string &s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, s.size() - 1, true);
    }
};

int main() {
    Solution obj;
    string s;
    cout << "Enter boolean expression: ";
    cin >> s;
    cout << "Number of ways to evaluate to TRUE: " << obj.countWays(s) << endl;
    return 0;
}

/*
Code Explanation:
-----------------
- dp[i][j][isTrue]: memoization table storing number of ways from index i to j to get True (isTrue=1) or False (isTrue=0).
- solve(): recursively splits the expression at every operator position and combines results from left and right using the truth tables.
- countWays(): initializes dp and calls solve() for the full string aiming for True.
- main(): takes input and prints result.
*/
