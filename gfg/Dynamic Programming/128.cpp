/*
==========================
    Stickler Thief II
==========================

QUESTION:
You are given an array arr[] representing houses arranged in a circle,
where each house has a certain value. A thief wants to maximize the stolen value
without robbing two adjacent houses. Since the houses are in a circle, 
the first and last houses are also considered adjacent.

Find the maximum amount the thief can steal.

EXAMPLES:
Input: arr = [2, 3, 2]
Output: 3
Explanation: Can't rob both house 0 and 2 as they are adjacent. Best: rob house 1 → 3.

Input: arr = [1, 2, 3, 1]
Output: 4
Explanation: Rob houses 0 and 2 → 1 + 3 = 4.

Input: arr = [2, 2, 3, 1, 2]
Output: 5
Explanation: Rob houses 0 & 2 (2 + 3) or 2 & 4 (3 + 2) → 5.

CONSTRAINTS:
2 ≤ arr.size() ≤ 10^5
0 ≤ arr[i] ≤ 10^4

-----------------------------------
APPROACH:
1. Since houses are in a circle, first and last are adjacent.
   This means we cannot rob both.
2. Split into two cases:
   Case 1 → Rob from house 0 to n-2 (exclude last)
   Case 2 → Rob from house 1 to n-1 (exclude first)
3. Solve each case like the normal House Robber problem.
4. For the linear version:
   dp[i] = max(dp[i-1], arr[i] + dp[i-2])
   Use two variables (O(1) space).
5. Final answer = max(case1, case2)

-----------------------------------
DRY RUN EXAMPLE:
arr = [1, 2, 3, 1]
Case 1: [1, 2, 3] → max = 4
Case 2: [2, 3, 1] → max = 3
Answer = max(4, 3) = 4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Helper function to solve linear House Robber
    int robLinear(vector<int> &arr, int start, int end) {
        int prev1 = 0, prev2 = 0;
        for (int i = start; i <= end; i++) {
            int pick = arr[i] + prev2; // Rob this house
            int skip = prev1;          // Skip this house
            int curr = max(pick, skip);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    // Main function for circular houses
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0]; // Only one house
        
        // Case 1: Exclude last house
        int case1 = robLinear(arr, 0, n - 2);
        // Case 2: Exclude first house
        int case2 = robLinear(arr, 1, n - 1);
        
        return max(case1, case2);
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {2, 3, 2};
    cout << obj.maxValue(arr1) << endl; // Output: 3

    vector<int> arr2 = {1, 2, 3, 1};
    cout << obj.maxValue(arr2) << endl; // Output: 4

    vector<int> arr3 = {2, 2, 3, 1, 2};
    cout << obj.maxValue(arr3) << endl; // Output: 5

    return 0;
}

/*
-----------------------------------
CODE EXPLANATION:
- robLinear():
    Takes a range of houses and computes the max stolen value without taking adjacent houses.
    Uses prev1 (dp[i-1]) and prev2 (dp[i-2]) to store previous results.
    At each house:
       pick = arr[i] + prev2
       skip = prev1
       curr = max(pick, skip)
    Update prev2 and prev1 for next iteration.

- maxValue():
    Handles the circular constraint:
       → Compute max loot excluding last house
       → Compute max loot excluding first house
    Return the maximum of the two.
*/
