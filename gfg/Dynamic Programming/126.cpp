#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem:
You are given an array prices[] where each element represents the stock price on that day.
You can make at most 2 transactions (buy->sell->buy->sell) to get the maximum profit.

Approach:
1. Do a left-to-right pass to find max profit from day 0 to i (left[i]).
2. Do a right-to-left pass to find max profit from day i to end (right[i]).
3. For each day i, total profit = left[i] + right[i].
4. Return the maximum of these total profits.
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // Step 1: Left pass - max profit from day 0 to i
        vector<int> left(n, 0);
        int min_price = prices[0];
        for (int i = 1; i < n; ++i) {
            min_price = min(min_price, prices[i]);
            left[i] = max(left[i - 1], prices[i] - min_price);
        }

        // Step 2: Right pass - max profit from day i to end
        vector<int> right(n, 0);
        int max_price = prices[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            max_price = max(max_price, prices[i]);
            right[i] = max(right[i + 1], max_price - prices[i]);
        }

        // Step 3: Combine left and right to find maximum profit
        int max_profit = 0;
        for (int i = 0; i < n; ++i) {
            max_profit = max(max_profit, left[i] + right[i]);
        }

        return max_profit;
    }
};

// Driver code to test the solution
int main() {
    Solution sol;

    // Example 1
    vector<int> prices1 = {10, 22, 5, 75, 65, 80};
    cout << "Max Profit (Example 1): " << sol.maxProfit(prices1) << endl;  // Output: 87

    // Example 2
    vector<int> prices2 = {2, 30, 15, 10, 8, 25, 80};
    cout << "Max Profit (Example 2): " << sol.maxProfit(prices2) << endl;  // Output: 100

    return 0;
}
