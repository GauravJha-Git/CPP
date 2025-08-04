#include <iostream>
#include <vector>
using namespace std;

/*
💡 Question: Partition Equal Subset Sum

Given an integer array `arr[]`, determine if it can be partitioned into two subsets such that 
the sum of elements in both subsets is equal.

Constraints:
- 1 ≤ arr.size ≤ 100
- 1 ≤ arr[i] ≤ 200

Examples:
Input:  arr = [1, 5, 11, 5]
Output: true
Explanation: The array can be split into [1, 5, 5] and [11], both have sum = 11

Input:  arr = [1, 3, 5]
Output: false
Explanation: No way to split into equal-sum subsets.
*/

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int total = 0;
        for (int num : arr) total += num;

        // If total is odd, we can't split equally
        if (total % 2 != 0) return false;

        int target = total / 2;
        int n = arr.size();

        // dp[i] = true if subset with sum 'i' is possible
        vector<bool> dp(target + 1, false);
        dp[0] = true; // base case

        for (int i = 0; i < n; ++i) {
            for (int j = target; j >= arr[i]; --j) {
                dp[j] = dp[j] || dp[j - arr[i]];
            }
        }

        return dp[target];
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {1, 5, 11, 5};
    cout << (sol.equalPartition(arr1) ? "true" : "false") << endl; // Output: true

    vector<int> arr2 = {1, 3, 5};
    cout << (sol.equalPartition(arr2) ? "true" : "false") << endl; // Output: false

    return 0;
}

/*
🔍 Approach: Subset Sum Using DP

- Calculate total sum of array.
- If sum is odd → cannot partition → return false.
- Else, check if a subset with sum = total / 2 exists.
- Use 1D DP where dp[i] = true means subset with sum i is possible.
- Update dp from back to front using current number.

✅ Time Complexity: O(n * sum/2)
✅ Space Complexity: O(sum/2)
*/
