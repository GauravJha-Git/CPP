#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
------------------------------------------
🔰 Problem: Longest Bounded-Difference Subarray

Given an array of positive integers arr[] and a non-negative integer x, 
find the longest contiguous subarray such that the absolute difference 
between the maximum and minimum element in the subarray is not more than x.

Return the subarray (not just the length). If multiple answers exist, 
return the one that starts at the smallest index.

🧩 Examples:

Input:  arr = [8, 4, 2, 6, 7], x = 4
Output: [4, 2, 6]

Input:  arr = [15, 10, 1, 2, 4, 7, 2], x = 5
Output: [2, 4, 7, 2]

------------------------------------------
🧠 Approach:

- Use Sliding Window technique with a multiset to keep elements sorted.
- Maintain the window as long as max - min ≤ x.
- If it exceeds, shrink from the left.
- Track the longest window and its start index.
------------------------------------------
*/

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        multiset<int> window;
        int start = 0, maxLen = 0, left = 0;

        for (int end = 0; end < arr.size(); end++) {
            window.insert(arr[end]);

            // Shrink the window if max - min > x
            while (*window.rbegin() - *window.begin() > x) {
                window.erase(window.find(arr[start]));
                start++;
            }

            // Update max length and starting index
            if (end - start + 1 > maxLen) {
                maxLen = end - start + 1;
                left = start;
            }
        }

        return vector<int>(arr.begin() + left, arr.begin() + left + maxLen);
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {8, 4, 2, 6, 7};
    int x1 = 4;
    vector<int> result1 = sol.longestSubarray(arr1, x1);
    cout << "Output 1: ";
    for (int num : result1) cout << num << " ";
    cout << endl;

    // Test Case 2
    vector<int> arr2 = {15, 10, 1, 2, 4, 7, 2};
    int x2 = 5;
    vector<int> result2 = sol.longestSubarray(arr2, x2);
    cout << "Output 2: ";
    for (int num : result2) cout << num << " ";
    cout << endl;

    return 0;
}

/*
📝 Output:
Output 1: 4 2 6 
Output 2: 2 4 7 2

🕒 Time Complexity: O(N log N) due to multiset insert and erase.
🔧 Space Complexity: O(N) for multiset.
*/
