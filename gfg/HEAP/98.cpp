/*
---------------------------------------------
🔷 Question: Median in a Stream
---------------------------------------------

You are given a stream of integers. After each new integer is added to the stream,
output the median of all elements so far.

📌 Definition of Median:
- If the count of numbers is ODD  → median = middle number.
- If the count of numbers is EVEN → median = average of two middle numbers.

---------------------------------------------
🔢 Example:

Input: arr[] = [5, 15, 1, 3, 2, 8]
Output: [5.0, 10.0, 5.0, 4.0, 3.0, 4.0]

Explanation:
- Stream: 5           → Median = 5.0
- Stream: 5, 15       → Median = (5+15)/2 = 10.0
- Stream: 5, 15, 1    → Median = 5.0
- Stream: 5, 15, 1, 3 → Median = (3+5)/2 = 4.0
- Stream: 5, 15, 1, 3, 2 → Median = 3.0
- Stream: 5, 15, 1, 3, 2, 8 → Median = (3+5)/2 = 4.0

---------------------------------------------
💡 Approach:

Use two heaps:
- Max Heap for the left half of numbers
- Min Heap for the right half

At each step:
1. Add the new number to the appropriate heap
2. Rebalance the heaps if needed
3. Compute the median using the tops of the heaps

---------------------------------------------
🧠 Why Two Heaps?

- maxHeap stores the smaller half (top is max of left side)
- minHeap stores the larger half (top is min of right side)
- Allows efficient retrieval of middle elements in O(1) time

---------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> getMedian(vector<int> &arr) {
        // Max heap for the left half
        priority_queue<int> maxHeap;

        // Min heap for the right half
        priority_queue<int, vector<int>, greater<int>> minHeap;

        vector<double> result;

        for (int num : arr) {
            // Step 1: Insert into appropriate heap
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }

            // Step 2: Balance the heaps
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            // Step 3: Calculate median
            if (maxHeap.size() == minHeap.size()) {
                double median = (maxHeap.top() + minHeap.top()) / 2.0;
                result.push_back(median);
            } else {
                result.push_back(maxHeap.top());
            }
        }

        return result;
    }
};

// -------------------------
// 🔁 Test the code
// -------------------------
int main() {
    Solution sol;
    vector<int> arr = {5, 15, 1, 3, 2, 8};

    vector<double> medians = sol.getMedian(arr);

    cout << "Medians in stream: ";
    for (double m : medians) {
        cout << m << " ";
    }
    cout << endl;

    return 0;
}

/*
---------------------------------------------
🧾 Code Explanation:

- maxHeap stores lower half (largest at top)
- minHeap stores higher half (smallest at top)

For each element:
1. Add to one of the heaps
2. Rebalance sizes if needed (maxHeap can have at most 1 extra)
3. If both heaps are same size → median = avg of tops
   Else → median = top of maxHeap

---------------------------------------------
📈 Time & Space Complexity:

⏱ Time: O(n log n)  → Each insertion in heap = log n
📦 Space: O(n)       → For two heaps and result array

---------------------------------------------
*/
