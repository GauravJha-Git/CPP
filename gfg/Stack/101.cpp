/*
  🔶 Problem: Next Greater Element
  --------------------------------
  Given an array `arr[]` of integers, find the next greater element
  for each element in the array.

  The next greater element of an element is the first element to its right
  which is greater than it. If no such element exists, use -1.

  📌 Examples:
  ----------
  Input: arr[] = {1, 3, 2, 4}
  Output:        [3, 4, 4, -1]

  Input: arr[] = {6, 8, 0, 1, 3}
  Output:        [8, -1, 1, 3, -1]

  Constraints:
  1 ≤ arr.size() ≤ 10^6
  0 ≤ arr[i] ≤ 10^9

  💡 Approach (Monotonic Stack):
  ------------------------------
  - Traverse the array from right to left.
  - Use a stack to keep potential next greater elements.
  - For each element:
    - Pop from the stack while the top is less than or equal to current element.
    - The top of the stack (if any) is the next greater.
    - Push the current element onto the stack.

  🧠 Time Complexity: O(N)
  🧠 Space Complexity: O(N)
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);  // default all to -1
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            // Remove elements smaller or equal
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                result[i] = st.top();  // Next greater found
            }

            st.push(arr[i]);  // Push current to stack
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    // Example test case
    vector<int> arr = {1, 3, 2, 4};

    vector<int> result = sol.nextLargerElement(arr);

    cout << "Next Greater Elements: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
