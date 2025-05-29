/*
🧩 Product Array Puzzle

Problem Statement:
Given an array arr[] of size n, construct a new array res[] such that:
res[i] is equal to the product of all the elements of arr[] except arr[i].

Constraints:
- 2 <= arr.size() <= 10^5
- -100 <= arr[i] <= 100
- Output values must fit in a 32-bit integer.

Example 1:
Input:  arr[] = [10, 3, 5, 6, 2]
Output: [180, 600, 360, 300, 900]

Example 2:
Input: arr[] = [12, 0]
Output: [0, 12]
*/

#include <iostream>
#include <vector>
using namespace std;

// ✅ Solution class with function
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 1);

        // Step 1: Calculate left product for each index
        int left = 1;
        for (int i = 0; i < n; i++) {
            res[i] = left;
            left *= arr[i];
        }

        // Step 2: Multiply with right product
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= right;
            right *= arr[i];
        }

        return res;
    }
};

// ✅ Main function to test
int main() {
    Solution sol;

    // You can modify this input
    vector<int> arr = {10, 3, 5, 6, 2};

    vector<int> result = sol.productExceptSelf(arr);

    cout << "Output: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}

/*
🧠 Code Explanation:

- We create a result array `res[]` initialized with 1s.
- First loop calculates the product of elements to the left of each index.
- Second loop calculates the product of elements to the right and multiplies it to the result.
- This gives the product of all elements except the current one.
- This method avoids using division and works even when the array contains zeros.

Output for [10, 3, 5, 6, 2]:
180 600 360 300 900
*/
