/*
📌 Question:
Given an integer array `arr[]`, count how many triplets can be chosen from the array such that they form a valid triangle.

A triplet (a, b, c) can form a triangle if and only if:
    a + b > c
    b + c > a
    a + c > b

For a sorted array, it's enough to check:
    a + b > c

Constraints:
    1 <= arr.size() <= 10^3
    0 <= arr[i] <= 10^5
*/

/*
✅ Approach:
1. Sort the array.
2. Fix the third side (largest value) as `arr[k]`.
3. Use two pointers `i` and `j` to find pairs such that:
      arr[i] + arr[j] > arr[k]
4. If true, all elements from `i` to `j-1` also satisfy the condition.
5. Count all such valid pairs.

⏱ Time Complexity: O(n^2)
📦 Space Complexity: O(1)
*/

/*
💡 Example:
Input: arr = [4, 6, 3, 7]
Sorted: [3, 4, 6, 7]
Valid triangles:
    (3, 4, 6)
    (3, 6, 7)
    (4, 6, 7)
Output: 3
*/

/*
⚠️ Problem Faced:
Originally, this line was written:
    count += (j - 1); ❌

This was wrong because it always subtracts 1, even when `i` was greater.

✅ Correct:
    count += (j - i);

This ensures we only count valid triangles formed between `i` and `j`.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        
        sort(arr.begin(), arr.end()); // Step 1: Sort the array
        
        // Step 2: Fix the third side from the end
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                // Step 3: Check triangle condition
                if (arr[i] + arr[j] > arr[k]) {
                    count += (j - i); // Count all valid pairs with arr[k]
                    j--;
                } else {
                    i++;
                }
            }
        }
        
        return count;
    }
};

// Optional: Main function for testing
int main() {
    Solution obj;
    vector<int> arr1 = {4, 6, 3, 7};
    vector<int> arr2 = {10, 21, 22, 100, 101, 200, 300};
    vector<int> arr3 = {1, 2, 3};
    
    cout << "Output 1: " << obj.countTriangles(arr1) << endl; // Expected: 3
    cout << "Output 2: " << obj.countTriangles(arr2) << endl; // Expected: 6
    cout << "Output 3: " << obj.countTriangles(arr3) << endl; // Expected: 0
    
    return 0;
}
