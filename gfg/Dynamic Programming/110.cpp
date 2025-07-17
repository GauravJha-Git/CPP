/*
📘 Problem: Longest Increasing Subsequence (LIS)
-----------------------------------------------
Given an array arr[] of non-negative integers, find the length of the Longest Strictly Increasing Subsequence (LIS).

A subsequence is strictly increasing if each element is strictly less than the next element.

Examples:

Input: arr[] = [5, 8, 3, 7, 9, 1]
Output: 3
Explanation: LIS can be [5, 7, 9]

Input: arr[] = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
Output: 6
Explanation: LIS can be [0, 2, 6, 9, 13, 15]

Input: arr[] = [3, 10, 2, 1, 20]
Output: 3
Explanation: LIS can be [3, 10, 20]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int lis(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1); // dp[i] = length of LIS ending at i

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end()); // final LIS length
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {5, 8, 3, 7, 9, 1};
    cout << "Length of LIS: " << sol.lis(arr1) << endl; // Output: 3

    vector<int> arr2 = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    cout << "Length of LIS: " << sol.lis(arr2) << endl; // Output: 6

    vector<int> arr3 = {3, 10, 2, 1, 20};
    cout << "Length of LIS: " << sol.lis(arr3) << endl; // Output: 3

    return 0;
}

/*
🧠 Approach:
------------
- Use Dynamic Programming (O(n^2) time).
- dp[i] stores length of longest increasing subsequence ending at index i.
- Initialize all dp[i] = 1.
- For each i, check all j < i.
    - If arr[j] < arr[i], update: dp[i] = max(dp[i], dp[j] + 1)
- The answer is the maximum in dp[].

🧠 Example for arr = [3, 10, 2, 1, 20]:
- Initial dp = [1, 1, 1, 1, 1]
- After computation:
  dp = [1, 2, 1, 1, 3]
- Answer = max(dp) = 3

🧩 Code Explanation:
--------------------
vector<int> dp(n, 1);            // Start with LIS length 1 at each index
for (int i = 1; i < n; ++i)      // Traverse the array
  for (int j = 0; j < i; ++j)    // Compare with all previous elements
    if (arr[j] < arr[i])         // If smaller, can extend subsequence
      dp[i] = max(dp[i], dp[j] + 1);
return max(dp);                 // Final answer
*/
