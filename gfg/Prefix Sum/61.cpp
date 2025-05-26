/*
=======================================
🧠 Question: Equilibrium Point
=======================================
Given an array `arr[]` of integers, find the first equilibrium index.

An equilibrium index is one where the sum of elements before it equals 
the sum of elements after it.

Return -1 if no such index exists.

Note: Indexing is 0-based.

--------------------------
Examples:
--------------------------

Input:  arr[] = [1, 2, 0, 3]
Output: 2
Explanation: 1 + 2 = 3 (left), 3 (right)

Input:  arr[] = [1, 1, 1, 1]
Output: -1
Explanation: No such index

Input:  arr[] = [-7, 1, 5, 2, -4, 3, 0]
Output: 3
Explanation: -7 + 1 + 5 = -1 (left), -4 + 3 + 0 = -1 (right)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int total = 0;
        for (int num : arr) {
            total += num;  // calculate total sum
        }

        int leftSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            total -= arr[i];  // total becomes right sum

            if (leftSum == total) {
                return i;  // equilibrium index found
            }

            leftSum += arr[i];  // update left sum
        }

        return -1;  // no equilibrium index found
    }
};

// ===============================
// 🔍 Code Explanation
// ===============================
//
// 1. First, compute total sum of all elements in the array.
// 2. Traverse the array, updating total to represent the right sum.
// 3. At each step, compare leftSum and right sum:
//    - If equal, return index.
//    - Otherwise, update leftSum and continue.
//
// ✅ Time Complexity: O(n)
// ✅ Space Complexity: O(1)

// ===============================
// 💻 Example Usage
// ===============================

int main() {
    Solution sol;
    vector<int> arr = {-7, 1, 5, 2, -4, 3, 0};
    int index = sol.findEquilibrium(arr);
    cout << "Equilibrium Index: " << index << endl;  // Output: 3
    return 0;
}
