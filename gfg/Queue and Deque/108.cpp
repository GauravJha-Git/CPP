/*
🧾 Problem: K-Sized Subarray Maximum

Given an array `arr[]` of size `n` and an integer `k`, find the maximum value 
in every contiguous subarray of size `k`.

📌 Input:
- Array `arr[]` of integers
- Integer `k`

📌 Output:
- A vector/array of maximum values in each subarray of size `k`

🔒 Constraints:
- 1 ≤ arr.size() ≤ 10^6
- 1 ≤ k ≤ arr.size()
- 0 ≤ arr[i] ≤ 10^9

🔍 Approach:
We use a double-ended queue (deque) to keep track of the indices of useful elements
for each window. It helps maintain the max element at the front.

Steps:
1. Loop through the array elements.
2. Remove indices from the deque that are out of the current window.
3. Remove indices of all elements smaller than current from the back of the deque.
4. Push the current index.
5. If we've processed at least k elements, push the front value (max) to result.

✅ Time Complexity: O(n)
✅ Space Complexity: O(k)
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> result;

        for (int i = 0; i < arr.size(); ++i) {
            // Remove elements out of this window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove all elements smaller than current
            while (!dq.empty() && arr[dq.back()] < arr[i])
                dq.pop_back();

            // Add current index
            dq.push_back(i);

            // If window has hit size k, record the max
            if (i >= k - 1)
                result.push_back(arr[dq.front()]);
        }

        return result;
    }
};

// MAIN FUNCTION to test the solution
int main() {
    Solution sol;

    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;

    vector<int> result = sol.maxOfSubarrays(arr, k);

    cout << "Max of each subarray of size " << k << ": ";
    for (int val : result)
        cout << val << " ";

    return 0;
}
