/*
📌 Problem: K Largest Elements
-----------------------------------
Given an array arr[] of positive integers and an integer k,
return the k largest elements in decreasing order.

🧪 Examples:
Input: arr = [1, 23, 12, 9, 30, 2, 50], k = 3
Output: [50, 30, 23]

Input: arr = [12, 5, 787, 1, 23], k = 2
Output: [787, 23]

✅ Constraints:
1 ≤ k ≤ arr.size() ≤ 10^6
1 ≤ arr[i] ≤ 10^6

✅ Approach:
- Use a min-heap (priority queue with smallest on top).
- Traverse the array and maintain a heap of size k.
- If the heap size is less than k, insert the element.
- If the current element is greater than the top (smallest),
  remove the top and insert the current element.
- At the end, the heap contains k largest elements.
- Pop all elements from heap into a result vector and sort in descending order.

⏱️ Time Complexity: O(n log k) for heap operations + O(k log k) for final sort.
🧠 Space Complexity: O(k) for heap and result vector.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Min-heap to store k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i = 0; i < arr.size(); ++i) {
            if(minHeap.size() < k)
                minHeap.push(arr[i]);
            else if(arr[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(arr[i]);
            }
        }

        // Extract elements from minHeap
        vector<int> result;
        while(!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        // Sort in descending order
        sort(result.rbegin(), result.rend());
        return result;
    }
};

int main() {
    vector<int> arr = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;

    Solution sol;
    vector<int> output = sol.kLargest(arr, k);

    cout << "Top " << k << " largest elements: ";
    for (int val : output) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
