/*
🧾 Problem: Min Cost Climbing Stairs

You're given an integer array cost[] where cost[i] is the cost to step on the i-th stair.
You can either start from index 0 or index 1 and move either 1 or 2 steps at a time.
Your goal is to reach just beyond the last step with minimum total cost.

Examples:
Input: [10, 15, 20]
Output: 15

Input: [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
*/

/*
🧠 Approach:
- Let dp[i] represent the minimum cost to reach step i.
- To reach step i, you can come from:
    1. dp[i-1] + cost[i-1]
    2. dp[i-2] + cost[i-2]
- So, dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])
- Space optimization: we only need the last two values (prev1 and prev2)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = 0; // Represents dp[i-2]
        int prev1 = 0; // Represents dp[i-1]

        for (int i = 2; i <= n; ++i) {
            int curr = min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1; // Minimum cost to reach the top
    }
};

int main() {
    Solution sol;

    vector<int> cost1 = {10, 15, 20};
    cout << "Output 1: " << sol.minCostClimbingStairs(cost1) << endl;  // Expected: 15

    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Output 2: " << sol.minCostClimbingStairs(cost2) << endl;  // Expected: 6

    return 0;
}
