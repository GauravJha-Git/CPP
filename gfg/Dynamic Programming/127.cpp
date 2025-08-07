/*
🧠 Problem: Stickler Thief

Description:
Stickler the thief wants to loot money from houses arranged in a line. He cannot loot two consecutive houses,
and wants to maximize the total loot.

Given:
An array arr[] of size n where arr[i] represents the amount of money at the i-th house.

Constraints:
1 ≤ n ≤ 10^5
1 ≤ arr[i] ≤ 10^4

Input:
arr[] = [6, 5, 5, 7, 4]
Output:
15

💡 Approach (Dynamic Programming):
We define:
    dp[i] = maximum loot possible up to house i.

Recurrence Relation:
    dp[i] = max(dp[i-1], arr[i] + dp[i-2])

We optimize space using two variables: prev1 and prev2.

🧮 Example Trace:
arr = [6, 5, 5, 7, 4]

dp[0] = 6
dp[1] = max(6, 5) = 6
dp[2] = max(6, 5+6) = 11
dp[3] = max(11, 7+6) = 13
dp[4] = max(13, 4+11) = 15
Answer = 15

✅ Time Complexity: O(n)
✅ Space Complexity: O(1) (Optimized)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];

        int prev2 = arr[0]; // dp[i-2]
        int prev1 = max(arr[0], arr[1]); // dp[i-1]

        for (int i = 2; i < n; ++i) {
            int curr = max(prev1, arr[i] + prev2); // dp[i]
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

// 🧪 Testing in main
int main() {
    Solution sol;

    vector<int> arr1 = {6, 5, 5, 7, 4};
    cout << "Max loot: " << sol.findMaxSum(arr1) << endl; // Output: 15

    vector<int> arr2 = {1, 5, 3};
    cout << "Max loot: " << sol.findMaxSum(arr2) << endl; // Output: 5

    vector<int> arr3 = {4, 4, 4, 4};
    cout << "Max loot: " << sol.findMaxSum(arr3) << endl; // Output: 8

    return 0;
}
