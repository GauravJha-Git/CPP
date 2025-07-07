/*
💼 Stock Span Problem

📌 Problem:
You are given an array of daily stock prices. For each day, calculate the stock span.

📌 Definition:
Span on a given day = Maximum number of consecutive days before it (including today) 
for which the price was <= price of today.

📌 Examples:
Input:  arr[] = {100, 80, 60, 70, 60, 75, 85}
Output:         1    1   1   2   1   4   6

Input:  arr[] = {10, 4, 5, 90, 120, 80}
Output:         1   1   2   4    5    1

📌 Constraints:
1 ≤ arr.size() ≤ 10^5
1 ≤ arr[i] ≤ 10^5

📌 Efficient Approach: Stack-based (O(N) Time)
- We use a stack to store indices of previous elements.
- For each day i:
    - Pop from stack while stack top is less than or equal to arr[i]
    - If stack is empty → span = i + 1
    - Else → span = i - st.top()
- Push current index i to the stack.

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to calculate stock spans
vector<int> calculateSpan(vector<int>& arr) {
    int n = arr.size();
    vector<int> span(n);
    stack<int> st; // stack to store indices

    for (int i = 0; i < n; i++) {
        // Pop indices with smaller or equal price
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        // Calculate span
        span[i] = st.empty() ? (i + 1) : (i - st.top());

        // Push current index
        st.push(i);
    }

    return span;
}

int main() {
    // Example input
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    // Get stock span
    vector<int> result = calculateSpan(prices);

    // Output result
    cout << "Stock Span: ";
    for (int s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
