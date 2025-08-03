/*
Subset Sum Problem
Difficulty: Medium
Accuracy: 32.0%
Submissions: 384K+
Points: 4

Problem:
Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to the given sum.

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true
Explanation: Subset {4, 3, 2} adds to 9.

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: No subset adds to 30.

Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: Whole array adds to 6.

Constraints:
1 <= arr.size() <= 200
1 <= arr[i] <= 200
1 <= sum <= 10^4

Approach: Dynamic Programming (Bottom-Up)

Idea:
We use a DP table dp[i][j] where:
- i → number of elements considered.
- j → current target sum.
- dp[i][j] is true if a subset from first i elements can give sum j.

Base Case:
- If sum is 0, subset always exists → dp[i][0] = true
- If no elements, non-zero sum is impossible → dp[0][j] = false for j > 0

DP Transition:
If current element arr[i-1] is greater than sum j, exclude it.
Else, include it OR exclude it:
    dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        // Base case: sum 0 is always possible
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j < arr[i - 1]) {
                    dp[i][j] = dp[i - 1][j]; // can't include current
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }

        return dp[n][sum];
    }
};

// Driver Code
int main() {
    Solution sol;

    vector<int> arr1 = {3, 34, 4, 12, 5, 2};
    int sum1 = 9;
    cout << "Input: sum = 9 => Output: " << (sol.isSubsetSum(arr1, sum1) ? "true" : "false") << endl;

    vector<int> arr2 = {3, 34, 4, 12, 5, 2};
    int sum2 = 30;
    cout << "Input: sum = 30 => Output: " << (sol.isSubsetSum(arr2, sum2) ? "true" : "false") << endl;

    vector<int> arr3 = {1, 2, 3};
    int sum3 = 6;
    cout << "Input: sum = 6 => Output: " << (sol.isSubsetSum(arr3, sum3) ? "true" : "false") << endl;

    return 0;
}
