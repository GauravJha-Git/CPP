/*
Problem: Missing in Array

You are given an array `arr[]` of size n-1 containing distinct integers from 1 to n.
One number from this range is missing. Find the missing number.

Example:
Input: arr = [1, 2, 3, 5]
Output: 4

Input: arr = [8, 2, 4, 5, 3, 7, 1]
Output: 6

Constraints:
1 ≤ arr.size() ≤ 10^6
1 ≤ arr[i] ≤ arr.size() + 1

Approach:
- Use the sum formula of first n natural numbers: total_sum = n*(n+1)/2
- Find the sum of elements in the array: arr_sum
- Missing number = total_sum - arr_sum
- Use long long to avoid integer overflow for large arrays

Algorithm:
1. Let n = arr.size() + 1
2. total_sum = n*(n+1)/2
3. Initialize arr_sum = 0
4. Loop through array and add each element to arr_sum
5. Return total_sum - arr_sum
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        long long n = arr.size() + 1;             // Total numbers
        long long total_sum = n * (n + 1) / 2;    // Sum of 1..n
        long long arr_sum = 0;
        
        for(int num : arr) {
            arr_sum += num;                        // Sum of array elements
        }
        
        return (int)(total_sum - arr_sum);         // Missing number
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> arr1 = {1, 2, 3, 5};
    cout << "Missing number in arr1: " << sol.missingNum(arr1) << endl;
    
    // Test Case 2
    vector<int> arr2 = {8, 2, 4, 5, 3, 7, 1};
    cout << "Missing number in arr2: " << sol.missingNum(arr2) << endl;
    
    // Test Case 3
    vector<int> arr3 = {1};
    cout << "Missing number in arr3: " << sol.missingNum(arr3) << endl;
    
    return 0;
}

/*
Code Explanation:
- Class Solution contains method missingNum.
- Use long long to avoid overflow for very large n.
- total_sum = sum of 1..n
- arr_sum = sum of array elements
- total_sum - arr_sum gives missing number
- main function tests the solution and prints results.

Time Complexity: O(n)
Space Complexity: O(1)
*/
