/*
Unique Number II

Question:
Given an array arr[] containing 2*n + 2 positive numbers, out of which 2*n numbers exist in pairs,
whereas only two numbers occur exactly once and are distinct. Find the other two numbers.
Return the answer in increasing order.

Example 1:
Input: arr[] = [1, 2, 3, 2, 1, 4]
Output: [3, 4]

Example 2:
Input: arr[] = [2, 1, 3, 2]
Output: [1, 3]

Example 3:
Input: arr[] = [2, 1, 3, 3]
Output: [1, 2]

Constraints:
2 ≤ arr.size() ≤ 10^6
1 ≤ arr[i] ≤ 5 * 10^6
arr.size() is even

Approach:
- Use XOR and bit manipulation:
  1. XOR all numbers → result = x ^ y (two unique numbers)
  2. Find a set bit in the XOR result (bit differs in x and y)
  3. Divide numbers into two groups based on this set bit:
       - Group 1: numbers with set bit
       - Group 2: numbers without set bit
  4. XOR each group separately → gives x and y
  5. Return in increasing order

Algorithm:
1. Initialize xor_all = 0
2. XOR all numbers in arr → xor_all = x ^ y
3. Find rightmost set bit in xor_all → set_bit = xor_all & (-xor_all)
4. Initialize num1 = 0, num2 = 0
5. For each number in arr:
     if number has set_bit → num1 ^= number
     else → num2 ^= number
6. Return [min(num1, num2), max(num1, num2)]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int xor_all = 0;
        for(int num : arr) xor_all ^= num;  // XOR of all elements

        // Find rightmost set bit
        int set_bit = xor_all & (-xor_all);

        int num1 = 0, num2 = 0;
        for(int num : arr) {
            if(num & set_bit)
                num1 ^= num;  // Group with set bit
            else
                num2 ^= num;  // Group without set bit
        }

        // Return in increasing order
        if(num1 > num2) swap(num1, num2);
        return {num1, num2};
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> arr1 = {1, 2, 3, 2, 1, 4};
    vector<int> res1 = sol.singleNum(arr1);
    cout << "Two unique numbers are: [" << res1[0] << ", " << res1[1] << "]" << endl; // Output: [3,4]

    // Test case 2
    vector<int> arr2 = {2, 1, 3, 2};
    vector<int> res2 = sol.singleNum(arr2);
    cout << "Two unique numbers are: [" << res2[0] << ", " << res2[1] << "]" << endl; // Output: [1,3]

    // Test case 3
    vector<int> arr3 = {2, 1, 3, 3};
    vector<int> res3 = sol.singleNum(arr3);
    cout << "Two unique numbers are: [" << res3[0] << ", " << res3[1] << "]" << endl; // Output: [1,2]

    return 0;
}

/*
Code Explanation:
1. XOR all numbers → xor_all = x ^ y (two unique numbers)
2. Find a set bit in xor_all → this bit differs in the two unique numbers
3. Split numbers into two groups based on this set bit
4. XOR each group separately → isolates the two unique numbers
5. Return in increasing order

Time Complexity: O(n) -> single pass through array
Space Complexity: O(1) -> constant extra space
*/
