/*
💼 Problem: Stock Buy and Sell – Max K Transactions Allowed

Difficulty: Hard
You are given:
- A list of stock prices: prices[] where prices[i] is the price on day i.
- An integer k – maximum number of transactions allowed.

Each transaction consists of buying and then selling a stock.
A new transaction can only start after the previous one is completed.

Your task is to return the maximum profit you can make with at most k transactions.

🧾 Examples:

Input: prices = [10, 22, 5, 80], k = 2
Output: 87
Explanation:
    1st transaction: Buy at 10, Sell at 22 → Profit = 12
    2nd transaction: Buy at 5, Sell at 80 → Profit = 75
    Total Profit = 12 + 75 = 87

Input: prices = [20, 580, 420, 900], k = 3
Output: 1040
Explanation:
    Buy at 20, Sell at 580 → Profit = 560
    Buy at 420, Sell at 900 → Profit = 480
    Total Profit = 1040

Input: prices = [100, 90, 80, 50, 25], k = 1
Output: 0
Explanation:
    Prices are falling, no profit can be made.

📌 Constraints:
- 1 ≤ prices.size() ≤ 1000
- 1 ≤ k ≤ 200
- 1 ≤ prices[i] ≤ 1000

🧠 Approach: Dynamic Programming

Let:
    dp[t][d] = max profit at day d with at most t transactions

We use the recurrence:
    dp[t][d] = max(dp[t][d-1], prices[d] + maxDiff)
    where maxDiff = max(maxDiff, dp[t-1][m] - prices[m]) for m < d

This avoids recalculating by storing the best day to buy using maxDiff

⏱ Time Complexity: O(k * n)
📦 Space Complexity: O(k * n)

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        // If k >= n/2, we can treat it as unlimited transactions
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            }
            return profit;
        }

        // DP table: dp[t][d] = max profit using at most t transactions up to day d
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));

        for (int t = 1; t <= k; ++t) {
            int maxDiff = -prices[0];
            for (int d = 1; d < n; ++d) {
                dp[t][d] = max(dp[t][d - 1], prices[d] + maxDiff);
                maxDiff = max(maxDiff, dp[t - 1][d] - prices[d]);
            }
        }

        return dp[k][n - 1];
    }
};

int main() {
    Solution sol;

    vector<int> prices1 = {10, 22, 5, 80};
    int k1 = 2;
    cout << "Max Profit 1: " << sol.maxProfit(k1, prices1) << endl;  // Output: 87

    vector<int> prices2 = {20, 580, 420, 900};
    int k2 = 3;
    cout << "Max Profit 2: " << sol.maxProfit(k2, prices2) << endl;  // Output: 1040

    vector<int> prices3 = {100, 90, 80, 50, 25};
    int k3 = 1;
    cout << "Max Profit 3: " << sol.maxProfit(k3, prices3) << endl;  // Output: 0

    return 0;
}
