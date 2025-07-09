/*
🧠 Problem: Max of Minimum for Every Window Size

Given an array arr[] of size n, find the maximum of minimums for every window size k where 1 <= k <= n.

Input:
- An array of integers arr[].

Output:
- An array res[] where res[k-1] is the maximum of minimums of all windows of size k.

Example:
Input:  arr = [10, 20, 30, 50, 10, 70, 30]
Output: [70, 30, 20, 10, 10, 10, 10]

Explanation:
For k = 1: windows = [10], [20], [30], ..., max(min) = 70
For k = 2: windows = [10, 20], [20, 30], ..., max(min) = 30
...
For k = 7: entire array → min = 10 → result = 10
*/

/*
🚀 Approach (Optimized O(n) using stacks):
1. For each element, find:
   - Previous smaller index (left)
   - Next smaller index (right)
2. Determine the maximum window size in which each element is minimum.
3. Use an array to store the maximum of such minimums for every window size.
4. Propagate the maximum values backwards to fill all window sizes.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s;

        // Find previous smaller element for each index
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear the stack
        while (!s.empty()) s.pop();

        // Find next smaller element for each index
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Initialize result array
        vector<int> res(n + 1, 0);

        // Fill result for each window size
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            res[len] = max(res[len], arr[i]);
        }

        // Fill the remaining entries
        for (int i = n - 1; i >= 1; i--) {
            res[i] = max(res[i], res[i + 1]);
        }

        // Final answer (ignore res[0])
        vector<int> ans(res.begin() + 1, res.end());
        return ans;
    }
};

// 🔁 Example usage with input and output
int main() {
    Solution sol;
    vector<int> arr = {10, 20, 30, 50, 10, 70, 30};
    vector<int> result = sol.maxOfMins(arr);

    cout << "Output: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

/*
🧠 Code Explanation:

- left[i] stores index of previous smaller element for arr[i]
- right[i] stores index of next smaller element for arr[i]
- Window size in which arr[i] is minimum = right[i] - left[i] - 1
- We use this window size to update result array with max of such minimums.
- Finally, we ensure that if any window size didn't get a value, it inherits the next bigger window's value.

⌛ Time Complexity: O(n)
🧠 Space Complexity: O(n)
*/
