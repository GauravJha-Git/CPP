/*
Unique Number I

Question:
Given an unsorted array arr[] of positive integers where all numbers occur exactly twice,
except for one number which occurs only once, find the number occurring only once.

Example 1:
Input: arr[] = [1, 2, 1, 5, 5]
Output: 2

Example 2:
Input: arr[] = [2, 30, 2, 15, 20, 30, 15]
Output: 20

Constraints:
1 ≤ arr.size() ≤ 10^6
0 ≤ arr[i] ≤ 10^9

Approach:
- Use XOR operation:
  1. a ^ a = 0
  2. a ^ 0 = a
  3. XOR is commutative and associative
- XOR all numbers, duplicates cancel out, leaving the unique number.

Algorithm:
1. Initialize unique = 0
2. For each number in arr:
       unique = unique ^ number
3. Return unique
*/

#include <iostream>
#include <vector>
using namespace std;

// Solution class
class Solution {
  public:
    int findUnique(vector<int> &arr) {
        int unique = 0;
        for(int num : arr) {
            unique ^= num;  // XOR all elements
        }
        return unique;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> arr1 = {1, 2, 1, 5, 5};
    cout << "Unique number is: " << sol.findUnique(arr1) << endl;  // Output: 2

    // Test case 2
    vector<int> arr2 = {2, 30, 2, 15, 20, 30, 15};
    cout << "Unique number is: " << sol.findUnique(arr2) << endl;  // Output: 20

    return 0;
}

/*
Code Explanation:
1. Initialize unique = 0.
2. Loop through each element and XOR it with unique.
3. Duplicates cancel out, leaving only the unique number.
4. Return the unique number.

Time Complexity: O(n) -> single pass
Space Complexity: O(1) -> constant space
*/
