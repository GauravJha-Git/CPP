/*
  📌 Problem: Longest Subarray with Sum K
  -------------------------------------------------
  Given an array of integers and a value k, find the length of the
  longest subarray whose sum is equal to k. Return 0 if none exists.

  🔢 Examples:
  Input:  arr = [10, 5, 2, 7, 1, -10], k = 15
  Output: 6

  Input:  arr = [-5, 8, -14, 2, 4, 12], k = -5
  Output: 5

  Input:  arr = [10, -10, 20, 30], k = 5
  Output: 0

  🔍 Approach:
  - Use prefix sum and a hashmap to store the earliest occurrence
    of each prefix sum.
  - For each element, check if (current_sum - k) exists in the map.
  - If it does, a valid subarray exists and we update the max length.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> prefix_sum_indices; // Stores first occurrence of each prefix sum
        int current_sum = 0;
        int max_len = 0;

        for (int i = 0; i < arr.size(); ++i) {
            current_sum += arr[i];

            // Case 1: Subarray from index 0 to i
            if (current_sum == k)
                max_len = i + 1;

            // Case 2: Subarray between previous prefix and current
            if (prefix_sum_indices.find(current_sum - k) != prefix_sum_indices.end()) {
                max_len = max(max_len, i - prefix_sum_indices[current_sum - k]);
            }

            // Case 3: Store first occurrence of current_sum
            if (prefix_sum_indices.find(current_sum) == prefix_sum_indices.end()) {
                prefix_sum_indices[current_sum] = i;
            }
        }

        return max_len;
    }
};

// ✅ Sample driver code
int main() {
    Solution sol;

    vector<int> arr1 = {10, 5, 2, 7, 1, -10};
    int k1 = 15;
    cout << "Test 1: " << sol.longestSubarray(arr1, k1) << endl;  // Output: 6

    vector<int> arr2 = {-5, 8, -14, 2, 4, 12};
    int k2 = -5;
    cout << "Test 2: " << sol.longestSubarray(arr2, k2) << endl;  // Output: 5

    vector<int> arr3 = {10, -10, 20, 30};
    int k3 = 5;
    cout << "Test 3: " << sol.longestSubarray(arr3, k3) << endl;  // Output: 0

    return 0;
}
