// Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr[].

// Note: It is guaranteed that the output fits in a 32-bit integer.

// Examples

// Input: arr[] = [-2, 6, -3, -10, 0, 2]
// Output: 180
// Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.

// To find the maximum product subarray, we can use a variation of Kadane's algorithm, keeping track of both:

// max_ending_here: the maximum product ending at the current position

// min_ending_here: the minimum product ending at the current position (important because a negative times negative can become the new max)

// 💡 Key Idea:
// Multiplying by a negative number swaps max and min — so we need both values at every step.

// code-

#include <bits/stdc++.h>

using namespace std;



// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        if (arr.empty()) return 0;

        int max_ending_here = arr[0];
        int min_ending_here = arr[0];
        int max_so_far = arr[0];

        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] < 0) {
                swap(max_ending_here, min_ending_here);
            }

            max_ending_here = max(arr[i], arr[i] * max_ending_here);
            min_ending_here = min(arr[i], arr[i] * min_ending_here);

            max_so_far = max(max_so_far, max_ending_here);
        }

        return max_so_far;
    }
};



int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

