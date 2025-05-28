/*
🔶 Problem: Largest Subarray of 0s and 1s
--------------------------------------------
You are given a binary array (containing only 0s and 1s).
Find the length of the longest contiguous subarray with an equal number of 0s and 1s.

🧾 Examples:

Input:  [1, 0, 1, 1, 1, 0, 0]
Output: 6
Explanation: Subarray [0, 1, 1, 1, 0, 0] has 3 zeros and 3 ones.

Input:  [0, 0, 1, 1, 0]
Output: 4
Explanation: Subarray [0, 0, 1, 1] or [0, 1, 1, 0].

Input:  [0]
Output: 0
Explanation: No equal number of 0s and 1s.

🧠 Approach:

1. Convert 0s to -1s.
2. Track prefix sums.
3. Use a hashmap to store the first occurrence of each prefix sum.
4. If the same prefix sum is found again, the subarray between those indices has equal 0s and 1s.

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(n)
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        unordered_map<int, int> prefixMap; // stores prefixSum -> firstIndex
        int maxLength = 0, prefixSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            // Convert 0 to -1 to use sum trick
            prefixSum += (arr[i] == 0) ? -1 : 1;

            if (prefixSum == 0) {
                // From start to i, subarray has equal 0s and 1s
                maxLength = i + 1;
            } else if (prefixMap.find(prefixSum) != prefixMap.end()) {
                // Found earlier, update max length
                maxLength = max(maxLength, i - prefixMap[prefixSum]);
            } else {
                // First time this prefixSum occurred
                prefixMap[prefixSum] = i;
            }
        }

        return maxLength;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {1, 0, 1, 1, 1, 0, 0};
    cout << "Test Case 1 Output: " << sol.maxLen(arr1) << endl;

    // Test Case 2
    vector<int> arr2 = {0, 0, 1, 1, 0};
    cout << "Test Case 2 Output: " << sol.maxLen(arr2) << endl;

    // Test Case 3
    vector<int> arr3 = {0};
    cout << "Test Case 3 Output: " << sol.maxLen(arr3) << endl;

    return 0;
}
