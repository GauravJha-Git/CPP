/*
Question: Histogram Max Rectangular Area

You are given a histogram represented by an array `arr[]`, where each element denotes the height of a bar in the histogram.
All bars have a width of 1 unit.

Your task is to find the area of the largest rectangle that can be formed by one or more contiguous bars.

Input:
- An array `arr[]` of size `n` (1 ≤ n ≤ 10^5), where each `arr[i]` (0 ≤ arr[i] ≤ 10^4) is the height of the i-th bar.

Output:
- Return an integer representing the maximum rectangular area possible in the histogram.

Approach:
To solve this problem efficiently, we use a stack to find:
1. Previous Smaller Element (PSE)
2. Next Smaller Element (NSE)

The idea is to find, for every bar, the largest rectangle where this bar is the smallest one.
The width of this rectangle is `right[i] - left[i] - 1`, and height is `arr[i]`.
We calculate area = height * width for each bar and return the maximum one.

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s;

        // Previous Smaller Element (PSE)
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear stack to reuse for NSE
        while (!s.empty()) s.pop();

        // Next Smaller Element (NSE)
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Calculate max area
        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int width = right[i] - left[i] - 1;
            int area = arr[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

// -------- Main Function ---------
int main() {
    Solution sol;
    
    vector<int> arr1 = {60, 20, 50, 40, 10, 50, 60};
    vector<int> arr2 = {3, 5, 1, 7, 5, 9};
    vector<int> arr3 = {3};

    cout << "Max Area (Test 1): " << sol.getMaxArea(arr1) << endl; // Output: 100
    cout << "Max Area (Test 2): " << sol.getMaxArea(arr2) << endl; // Output: 15
    cout << "Max Area (Test 3): " << sol.getMaxArea(arr3) << endl; // Output: 3

    return 0;
}
