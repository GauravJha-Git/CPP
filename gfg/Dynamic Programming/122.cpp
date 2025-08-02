/*
Minimum Jumps to Reach End

Difficulty: Medium

🔸 Problem:
You are given an array arr[] of non-negative integers. Each element represents 
the maximum number of steps you can jump forward from that position.

Your task is to find the **minimum number of jumps** needed to move from the 
first index to the last. If the end isn’t reachable, return -1.

🔸 Examples:

Input: arr = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
Output: 3

Input: arr = [1, 4, 3, 2, 6, 7]
Output: 2

Input: arr = [0, 10, 20]
Output: -1

🔸 Constraints:
2 ≤ arr.size() ≤ 10^4
0 ≤ arr[i] ≤ 10^4

🔸 Approach (Greedy):
- Track the farthest reachable index at any step.
- Track how many steps are left in the current jump.
- When steps run out, increment the jump count and update steps.
- If you’re stuck (i >= maxReach), return -1.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;         // Already at the end
        if (arr[0] == 0) return -1;   // Can't move anywhere

        int jumps = 1;                // Minimum one jump needed
        int maxReach = arr[0];       // Farthest we can reach initially
        int steps = arr[0];          // Steps available from current position

        for (int i = 1; i < n; i++) {
            if (i == n - 1) return jumps;  // Reached the end

            maxReach = max(maxReach, i + arr[i]);  // Update farthest reach
            steps--;  // Use one step

            if (steps == 0) {  // Need to jump
                jumps++;       // Increase jump count
                if (i >= maxReach) return -1;  // Cannot move forward
                steps = maxReach - i;  // Steps for next jump range
            }
        }

        return -1;  // If we exit the loop, we can't reach the end
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout << "Minimum jumps: " << obj.minJumps(arr1) << endl;  // Output: 3

    vector<int> arr2 = {1, 4, 3, 2, 6, 7};
    cout << "Minimum jumps: " << obj.minJumps(arr2) << endl;  // Output: 2

    vector<int> arr3 = {0, 10, 20};
    cout << "Minimum jumps: " << obj.minJumps(arr3) << endl;  // Output: -1

    return 0;
}
