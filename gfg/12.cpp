// Max Circular Subarray Sum
// Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular.

// Examples:

// Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
// Output: 22
// Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.

// To solve this problem, we can use a combination of Kadane’s algorithm and a trick for circular arrays.

// 🔍 Key Concepts:
// Kadane’s Algorithm gives the maximum subarray sum in a linear array.

// In a circular array, the maximum sum subarray can be either:

// a subarray that doesn’t wrap (use standard Kadane's), or

// a subarray that wraps around. To compute this:

// Find the total sum of the array.

// Find the minimum subarray sum (using Kadane’s on -arr).

// The max circular sum = totalSum - minSubarraySum.

// ✅ Steps:
// Use Kadane's to find max_kadane (normal max subarray sum).

// Calculate total array sum.

// Use modified Kadane's to find min_kadane (minimum subarray sum).

// Compute max_wrap = total_sum - min_kadane.

// Final result = max(max_kadane, max_wrap) unless all elements are negative.

// code-

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();

        // Step 1: Standard Kadane’s Algorithm to find max subarray sum
        int max_kadane = arr[0];
        int current_max = arr[0];
        for (int i = 1; i < n; i++) {
            current_max = max(arr[i], current_max + arr[i]);
            max_kadane = max(max_kadane, current_max);
        }

        // Step 2: Find total sum and minimum subarray sum
        int total_sum = 0;
        int min_kadane = arr[0];
        int current_min = arr[0];
        for (int i = 0; i < n; i++) {
            total_sum += arr[i];
            if (i > 0) {
                current_min = min(arr[i], current_min + arr[i]);
                min_kadane = min(min_kadane, current_min);
            }
        }

        int max_wrap = total_sum - min_kadane;

        // If all elements are negative, max_wrap will be 0, so return max_kadane
        if (max_wrap == 0)
            return max_kadane;

        return max(max_kadane, max_wrap);
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

