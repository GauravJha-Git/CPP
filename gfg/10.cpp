// Kadane's Algorithm
// Given an integer array arr[]. You need to find the maximum sum of a subarray.

// Examples:

// Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
// Output: 11
// Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.

// 📘 Kadane’s Algorithm Explanation:
// Problem: Find the maximum sum of a contiguous subarray.

// 💡 Idea:
// While iterating, we have two choices at every element:

// Either start a new subarray from this element,

// Or add this element to the existing subarray.

// We keep track of the best (max_so_far) and the current best subarray sum (current_max).

// 🧠 Step-by-Step:
// Let arr = [2, 3, -8, 7, -1, 2, 3]

// Start with:
// current_max = max_so_far = 2

// Next elements:

// 3: current_max = max(3, 2+3) = 5, max_so_far = 5

// -8: current_max = max(-8, 5-8) = -3, max_so_far = 5

// 7: current_max = max(7, -3+7) = 7, max_so_far = 7

// -1: current_max = max(-1, 7-1) = 6, max_so_far = 7

// 2: current_max = max(2, 6+2) = 8, max_so_far = 8

// 3: current_max = max(3, 8+3) = 11, max_so_far = 11

// ✅ Final result: 11

// code-


#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int max_so_far = arr[0];
        int current_max = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            current_max = max(arr[i], current_max + arr[i]);
            max_so_far = max(max_so_far, current_max);
        }

        return max_so_far;
    }
};



int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl << "~" << endl;
    }
}

