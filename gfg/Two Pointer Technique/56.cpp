// Indexes of Subarray Sum
// Difficulty: MediumAccuracy: 16.5%Submissions: 1.8MPoints: 4Average Time: 20m
// Given an array arr[] containing only non-negative integers, your task is to find a continuous subarray (a contiguous sequence of elements) whose sum equals a specified value target. You need to return the 1-based indices of the leftmost and rightmost elements of this subarray. You need to find the first subarray whose sum is equal to the target.

// Note: If no such array is possible then, return [-1].

// Examples:

// Input: arr[] = [1, 2, 3, 7, 5], target = 12
// Output: [2, 4]
// Explanation: The sum of elements from 2nd to 4th position is 12.
// Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], target = 15
// Output: [1, 5]
// Explanation: The sum of elements from 1st to 5th position is 15.
// Input: arr[] = [5, 3, 4], target = 2
// Output: [-1]
// Explanation: There is no subarray with sum 2.
// Constraints:
// 1 <= arr.size()<= 106
// 0 <= arr[i] <= 103
// 0 <= target <= 109
// 🔍 Approach: Sliding Window
// Since all elements are non-negative, we use the two-pointer sliding window method to find a continuous subarray.

// 📘 Explanation:
// Start with start = 0, curr_sum = 0.

// Add elements one by one using end pointer.

// If curr_sum > target, reduce it by removing elements from the start.

// If curr_sum == target, return the indices.
// code-
#include <iostream>
#include <vector>
using namespace std;

// ✅ Sliding Window Approach for non-negative integers
// Goal: Find the FIRST continuous subarray whose sum is equal to the target

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int start = 0, curr_sum = 0;

        for (int end = 0; end < arr.size(); end++) {
            curr_sum += arr[end]; // Expand the window

            // Shrink the window if sum exceeds target
            while (curr_sum > target && start < end) {
                curr_sum -= arr[start++];
            }

            // Target matched
            if (curr_sum == target) {
                return {start + 1, end + 1}; // Return 1-based indices
            }
        }

        return {-1}; // No such subarray found
    }
};

// ✅ Helper to print vector
void printResult(const vector<int> &res) {
    for (int num : res) cout << num << " ";
    cout << endl;
}

int main() {
    Solution sol;

    // ✅ Question 1
    // Input: arr = [1, 2, 3, 7, 5], target = 12
    // Explanation: 2nd to 4th → 2+3+7 = 12
    vector<int> arr1 = {1, 2, 3, 7, 5};
    cout << "Question 1 Output: ";
    printResult(sol.subarraySum(arr1, 12));

    // ✅ Question 2
    // Input: arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], target = 15
    // Explanation: 1st to 5th → 1+2+3+4+5 = 15
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Question 2 Output: ";
    printResult(sol.subarraySum(arr2, 15));

    // ✅ Question 3
    // Input: arr = [5, 3, 4], target = 2
    // Explanation: No subarray adds to 2
    vector<int> arr3 = {5, 3, 4};
    cout << "Question 3 Output: ";
    printResult(sol.subarraySum(arr3, 2));

    // ✅ Question 4
    // Input: arr = [0, 0, 0, 0], target = 0
    // Explanation: First 0 matches target
    vector<int> arr4 = {0, 0, 0, 0};
    cout << "Question 4 Output: ";
    printResult(sol.subarraySum(arr4, 0));

    // ✅ Question 5
    // Input: arr = [1, 4, 20, 3, 10, 5], target = 33
    // Explanation: 20+3+10 = 33 → 3rd to 5th
    vector<int> arr5 = {1, 4, 20, 3, 10, 5};
    cout << "Question 5 Output: ";
    printResult(sol.subarraySum(arr5, 33));

    return 0;
}

