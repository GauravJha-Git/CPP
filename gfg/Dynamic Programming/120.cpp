// 🧾 Coin Change (Count Ways)
// Given an array coins[] representing different denominations of currency and 
// an integer sum, find the number of ways to make the sum using an infinite 
// supply of coins. Each coin can be used as many times as needed.

// ✅ Example 1:
// Input: coins[] = {1, 2, 3}, sum = 4
// Output: 4
// Explanation: [1+1+1+1], [1+1+2], [2+2], [1+3]

// ✅ Example 2:
// Input: coins[] = {2, 5, 3, 6}, sum = 10
// Output: 5

// ✅ Example 3:
// Input: coins[] = {5, 10}, sum = 3
// Output: 0

// 💡 Approach: Dynamic Programming (1D Tabulation)
// - Create a dp array where dp[i] represents the number of ways to make sum i.
// - Initialize dp[0] = 1 (base case: one way to make sum 0 with no coins).
// - For each coin, update dp from coin to sum: dp[i] += dp[i - coin].

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        vector<int> dp(sum + 1, 0);
        dp[0] = 1; // Base case: 1 way to make sum 0

        for (int coin : coins) {
            for (int i = coin; i <= sum; i++) {
                dp[i] += dp[i - coin];
            }
        }

        return dp[sum];
    }
};

int main() {
    Solution sol;

    vector<int> coins1 = {1, 2, 3};
    int sum1 = 4;
    cout << "Number of ways for sum = " << sum1 << ": " 
         << sol.count(coins1, sum1) << endl;  // Output: 4

    vector<int> coins2 = {2, 5, 3, 6};
    int sum2 = 10;
    cout << "Number of ways for sum = " << sum2 << ": " 
         << sol.count(coins2, sum2) << endl;  // Output: 5

    vector<int> coins3 = {5, 10};
    int sum3 = 3;
    cout << "Number of ways for sum = " << sum3 << ": " 
         << sol.count(coins3, sum3) << endl;  // Output: 0

    return 0;
}
