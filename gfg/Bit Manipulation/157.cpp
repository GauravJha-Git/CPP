/*
📌 Question:
Find Only Repetitive Element from 1 to n-1

You are given an array arr[] of size n, containing numbers from 1 to n-1 in random order.
The array has exactly one repetitive element. Your task is to find that element.

Note: It is guaranteed that there is a repeating element present in the array.

Examples:
Input: arr[] = [1, 3, 2, 3, 4]
Output: 3

Input: arr[] = [1, 5, 1, 2, 3, 4]
Output: 1

Input: arr[] = [1, 1]
Output: 1

Constraints:
2 ≤ arr.size() ≤ 100000
1 ≤ arr[i] ≤ n-1
*/

/*
📌 Approach:
- The array has size n.
- Elements are from 1 to n-1.
- So, without repetition, the sum should be:
    expectedSum = (n-1)*n / 2
- The array has one duplicate, so:
    repeatedNumber = actualSum - expectedSum
*/

/*
📌 Algorithm:
1. Find the actual sum of elements in arr.
2. Compute the expected sum of 1 to n-1.
3. Subtract: duplicate = actualSum - expectedSum.
4. Return duplicate.
*/

/*
📌 Time Complexity: O(n)
📌 Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        long long actualSum = 0;

        // Step 1: Calculate sum of all array elements
        for (int x : arr) {
            actualSum += x;
        }

        // Step 2: Calculate expected sum of numbers from 1 to n-1
        long long expectedSum = (long long)(n - 1) * n / 2;

        // Step 3: Difference = duplicate number
        return (int)(actualSum - expectedSum);
    }
};

int main() {
    Solution s;

    // Example test cases
    vector<int> arr1 = {1, 3, 2, 3, 4};
    cout << "Duplicate in arr1: " << s.findDuplicate(arr1) << endl;

    vector<int> arr2 = {1, 5, 1, 2, 3, 4};
    cout << "Duplicate in arr2: " << s.findDuplicate(arr2) << endl;

    vector<int> arr3 = {1, 1};
    cout << "Duplicate in arr3: " << s.findDuplicate(arr3) << endl;

    return 0;
}

/*
📌 Code Explanation:
- findDuplicate():
  - Loops through the array to compute the actual sum.
  - Computes expected sum using formula for natural numbers.
  - Returns (actualSum - expectedSum), which is the duplicate element.

- main():
  - Creates three sample arrays.
  - Prints the duplicate element for each.
*/
