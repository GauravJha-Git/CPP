// Problem: Sum Pair Closest to Target
// Difficulty: Easy

/*
📝 Question:
Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a <= b,
whose sum is closest to target.

Rules:
- Return the pair in sorted order.
- If multiple such pairs exist, return the pair with maximum absolute difference.
- If no such pair exists, return an empty array.

Examples:

Input: arr[] = [10, 30, 20, 5], target = 25
Output: [5, 20]

Input: arr[] = [5, 2, 7, 1, 4], target = 10
Output: [2, 7]

Input: arr[] = [10], target = 10
Output: []

✅ Constraints:
1 <= arr.size() <= 2*10^5
0 <= target <= 2*10^5
0 <= arr[i] <= 10^5
*/

/*
💡 Approach:
1. Sort the array to use two pointers.
2. Initialize left = 0, right = n-1.
3. Use two pointers to scan all pairs and find:
   - Closest sum to target
   - In case of tie, pick the one with maximum absolute difference.
4. Return the best pair in sorted order.
*/

//----------------- Start of Code -----------------

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        if (n < 2) return {};

        sort(arr.begin(), arr.end());
        int left = 0, right = n - 1;
        int closest_diff = INT_MAX;
        int max_abs_diff = -1;
        vector<int> best_pair;

        while (left < right) {
            int a = arr[left];
            int b = arr[right];
            int curr_sum = a + b;
            int curr_diff = abs(curr_sum - target);
            int abs_diff = abs(a - b);

            if (curr_diff < closest_diff ||
               (curr_diff == closest_diff && abs_diff > max_abs_diff)) {
                closest_diff = curr_diff;
                max_abs_diff = abs_diff;
                best_pair = {a, b};
            }

            if (curr_sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return best_pair;
    }
};

// Driver Code (Do not change this)
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

/*
🧾 Code Explanation:
- Sort the array to use two pointers effectively.
- `left` starts at 0, `right` at n-1.
- We calculate the current pair sum and its distance from the target.
- If this is better than the previous best, update the best pair.
- If multiple pairs have the same closeness, prefer the one with greater absolute difference.
- Move pointers accordingly: if sum < target, move left++; else, right--.

⏱️ Time Complexity: O(n log n)
📦 Space Complexity: O(1)
*/

//----------------- End of Code -----------------
