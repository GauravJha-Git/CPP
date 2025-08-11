#include <bits/stdc++.h>
using namespace std;

/*
================== Question ==================
Given an array arr[] which represents the dimensions of a sequence of matrices 
where the ith matrix has dimensions (arr[i-1] x arr[i]) for i>=1, 
find the minimum number of scalar multiplications needed to multiply all matrices.

Example 1:
Input: arr = [2, 1, 3, 4]
Output: 20
Explanation:
M1: 2x1, M2: 1x3, M3: 3x4
Two ways:
1) ((M1 x M2) x M3) => cost = (2*1*3) + (2*3*4) = 6 + 24 = 30
2) (M1 x (M2 x M3)) => cost = (1*3*4) + (2*1*4) = 12 + 8 = 20 ✅ Minimum.

Example 2:
Input: arr = [1, 2, 3, 4, 3]
Output: 30
Explanation:
M1: 1x2, M2: 2x3, M3: 3x4, M4: 4x3
Order: ((M1 x M2) x M3) x M4 => cost = 6 + 12 + 12 = 30.

Constraints:
2 ≤ arr.size() ≤ 100
1 ≤ arr[i] ≤ 200
*/

/*
================== Approach ==================
We use Dynamic Programming.

Let dp[i][j] = minimum cost to multiply matrices from index i to j (1-based indexing for matrices).
Base Case: dp[i][i] = 0 (only one matrix, no multiplication needed).

Recurrence:
For each possible split point k between i and j:
dp[i][j] = min(dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j])

We compute dp for increasing chain lengths (bottom-up).
Time Complexity: O(N^3)
Space Complexity: O(N^2)
*/

/*
================== Code ==================
*/
class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int N = arr.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));

        // len = chain length
        for (int len = 2; len < N; len++) {
            for (int i = 1; i < N - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[1][N-1];
    }
};

/*
================== Code Explanation ==================
1. dp[i][j] stores min scalar multiplications to multiply matrices from index i to j.
2. Outer loop (len): Controls length of matrix chain (starts from 2).
3. Middle loop (i): Sets the starting matrix index.
4. Inner loop (k): Splits the chain at k.
   - dp[i][k]: Cost of multiplying first half
   - dp[k+1][j]: Cost of multiplying second half
   - arr[i-1] * arr[k] * arr[j]: Cost of multiplying the results
5. Answer: dp[1][N-1]
*/

int main() {
    Solution sol;

    vector<int> arr1 = {2, 1, 3, 4};
    cout << sol.matrixMultiplication(arr1) << endl; // Expected: 20

    vector<int> arr2 = {1, 2, 3, 4, 3};
    cout << sol.matrixMultiplication(arr2) << endl; // Expected: 30

    vector<int> arr3 = {3, 4};
    cout << sol.matrixMultiplication(arr3) << endl; // Expected: 0

    return 0;
}
