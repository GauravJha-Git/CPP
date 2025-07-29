/*
🧠 Problem: 0-1 Knapsack

Given `n` items, each with a weight and a value, and a knapsack with a capacity `W`.
Maximize the total value you can put in the knapsack without exceeding the weight `W`.

You can either include an item completely or not at all.

📥 Input Example:
W = 5
val[] = {10, 40, 30, 50}
wt[]  = {5, 4, 2, 3}

📤 Output:
80

🧾 Explanation:
Choose items with weight 2 (value 30) and weight 3 (value 50), total value = 80.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        // i = item index (1 to n)
        // w = current weight capacity (0 to W)
        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (wt[i - 1] <= w) {
                    // Item can be included
                    dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
                } else {
                    // Item can't be included
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        return dp[n][W]; // Max value using all n items and capacity W
    }
};

int main() {
    Solution sol;
    int W = 5;
    vector<int> val = {10, 40, 30, 50};
    vector<int> wt = {5, 4, 2, 3};

    int result = sol.knapsack(W, val, wt);
    cout << "Maximum value in knapsack = " << result << endl;

    return 0;
}

/*
🔍 Code Explanation:

- dp[i][w]: Max value using first i items with total weight capacity w.
- For each item, we decide:
  ➤ Exclude it → dp[i][w] = dp[i-1][w]
  ➤ Include it (if it fits) → dp[i][w] = val[i-1] + dp[i-1][w - wt[i-1]]
- Use the maximum of both choices.
- Final result is in dp[n][W].

✅ Time Complexity: O(n * W)
✅ Space Complexity: O(n * W)
*/
