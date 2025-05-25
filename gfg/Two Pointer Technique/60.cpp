/*
    📘 QUESTION: Container With Most Water

    You are given an array `arr[]` of non-negative integers where each element represents the height of a vertical line drawn on the x-axis.
    Find two lines such that they, along with the x-axis, form a container that holds the maximum amount of water.

    🔒 Constraints:
    - 1 <= arr.size() <= 10^5
    - 1 <= arr[i] <= 10^4

    🧠 APPROACH: Two Pointer Technique
    - Place two pointers at the start and end.
    - Compute area: min(height[left], height[right]) * (right - left)
    - Move the pointer pointing to the shorter line inward.
    - Keep updating the maximum area.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxWater(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int height = min(arr[left], arr[right]);
            int width = right - left;
            int area = height * width;
            maxArea = max(maxArea, area);

            // Move the pointer with the smaller height
            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};

/*
    📊 EXAMPLE:

    Input: [2, 1, 8, 6, 4, 6, 5, 5]
    Output: 25

    Explanation:
    - Best lines are at index 2 and index 7 => height = min(8, 5) = 5
    - Distance = 7 - 2 = 5
    - Area = 5 * 5 = 25
*/

int main() {
    Solution sol;
    vector<int> arr = {2, 1, 8, 6, 4, 6, 5, 5};
    cout << "Maximum Water Container Area: " << sol.maxWater(arr) << endl;
    return 0;
}

/*
    🔍 CODE EXPLANATION:

    - left = 0, right = arr.size() - 1: start from both ends
    - while (left < right): process until pointers meet
    - height = min(arr[left], arr[right]): height is the shorter one
    - width = right - left: horizontal distance
    - area = height * width: current container area
    - maxArea = max(maxArea, area): update max area
    - Move the pointer with the smaller height inward
*/
