/*

📘 PROBLEM: Trapping Rain Water

Given an array `arr[]` of non-negative integers representing the height of blocks, 
where the width of each block is 1, compute how much water can be trapped between 
the blocks during the rainy season.

🔹 Constraints:
- 1 < arr.size() < 10^5
- 0 ≤ arr[i] < 10^3

🧪 Examples:

Input:  arr[] = [3, 0, 1, 0, 4, 0, 2]
Output: 10

Input:  arr[] = [3, 0, 2, 0, 4]
Output: 7

Input:  arr[] = [1, 2, 3, 4]
Output: 0

Input:  arr[] = [2, 1, 5, 3, 1, 0, 4]
Output: 9

------------------------------------------------------------

🧠 APPROACH: Two-pointer method (Optimal)

1. Use two pointers: `left` and `right` starting from both ends of the array.
2. Maintain `left_max` and `right_max` to keep track of the highest bar seen so far from the left and right.
3. Water can only be trapped if a bar is lower than the maximum height on both sides.
4. Move the pointer with the smaller height, and calculate trapped water at that position.

💡 Water at any block `i` is: min(max_left, max_right) - height[i]

⏱ Time Complexity: O(n)
📦 Space Complexity: O(1)

------------------------------------------------------------

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxWater(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2) return 0;

        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int water_trapped = 0;

        while(left < right) {
            if(arr[left] < arr[right]) {
                if(arr[left] >= left_max)
                    left_max = arr[left];
                else
                    water_trapped += left_max - arr[left];
                left++;
            } else {
                if(arr[right] >= right_max)
                    right_max = arr[right];
                else
                    water_trapped += right_max - arr[right];
                right--;
            }
        }

        return water_trapped;
    }
};

int main() {
    Solution sol;
    
    // Example test case
    vector<int> arr = {3, 0, 1, 0, 4, 0, 2};
    
    cout << "Water trapped: " << sol.maxWater(arr) << " units" << endl;
    
    return 0;
}

/*

🧾 CODE EXPLANATION:

- `left`, `right`: Pointers to traverse from both ends.
- `left_max`, `right_max`: Track the tallest blocks from left and right.
- At each step:
  - If arr[left] < arr[right]:
    - If arr[left] > left_max → update left_max
    - Else → water = left_max - arr[left]
    - Move left++
  - Else:
    - If arr[right] > right_max → update right_max
    - Else → water = right_max - arr[right]
    - Move right--

The water is added to the total only when there's a taller bar on both sides.
*/
