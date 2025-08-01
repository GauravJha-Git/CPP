/*
==========================================
🟨 Coin Change (Minimum Coins) Problem
==========================================

🔶 Problem:
You are given an array coins[], where each element represents a coin of a different denomination,
and a target value `sum`. You have an unlimited supply of each coin type.

Your task is to determine the minimum number of coins needed to obtain the target sum.
If it is not possible to form the sum using the given coins, return -1.

🔹 Examples:
Input: coins[] = [25, 10, 5], sum = 30
Output: 2
Explanation: Minimum 2 coins needed: 25 + 5

Input: coins[] = [9, 6, 5, 1], sum = 19
Output: 3
Explanation: 19 = 9 + 9 + 1

Input: coins[] = [5, 1], sum = 0
Output: 0
Explanation: 0 sum needs 0 coins.

Input: coins[] = [4, 6, 2], sum = 5
Output: -1
Explanation: Not possible to make the given sum.

🔹 Constraints:
- 1 ≤ sum * coins.size() ≤ 10^6
- 0 <= sum <= 10^4
- 1 <= coins[i] <= 10^4
- 1 <= coins.size() <= 10^3
*/


/*
==========================================
🔍 Approach:
==========================================
1. Use bottom-up Dynamic Programming.
2. Create a dp[] array of size sum + 1.
3. dp[i] stores the minimum number of coins needed to make sum i.
4. Initialize dp[0] = 0 and others as INT_MAX - 1.
5. For every coin, update dp[i] = min(dp[i], dp[i - coin] + 1).
6. If dp[sum] remains INT_MAX - 1, return -1.
*/


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        vector<int> dp(sum + 1, INT_MAX - 1);  // initialize all to large number
        dp[0] = 0;  // base case

        for (int coin : coins) {
            for (int i = coin; i <= sum; ++i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return (dp[sum] == INT_MAX - 1) ? -1 : dp[sum];
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> coins1 = {25, 10, 5};
    int sum1 = 30;
    cout << "Input: [25, 10, 5], Sum = 30\nOutput: " << sol.minCoins(coins1, sum1) << "\n\n";

    // Test case 2
    vector<int> coins2 = {9, 6, 5, 1};
    int sum2 = 19;
    cout << "Input: [9, 6, 5, 1], Sum = 19\nOutput: " << sol.minCoins(coins2, sum2) << "\n\n";

    // Test case 3
    vector<int> coins3 = {5, 1};
    int sum3 = 0;
    cout << "Input: [5, 1], Sum = 0\nOutput: " << sol.minCoins(coins3, sum3) << "\n\n";

    // Test case 4
    vector<int> coins4 = {4, 6, 2};
    int sum4 = 5;
    cout << "Input: [4, 6, 2], Sum = 5\nOutput: " << sol.minCoins(coins4, sum4) << "\n";

    return 0;
}


/*
==========================================
🧾 Code Explanation:
==========================================
- We initialize a dp array of size (sum + 1) with large values.
- dp[0] = 0 because 0 coins are needed to make sum = 0.
- For each coin, we update dp[i] where i >= coin.
- dp[i] = min(dp[i], dp[i - coin] + 1) → using this coin may reduce total.
- After filling dp[], if dp[sum] is still very large, return -1.
*/


/*
==========================================
⏱️ Time & Space Complexity:
==========================================
Time Complexity:  O(N * sum)
Space Complexity: O(sum)
Where N = number of coins.
*/
