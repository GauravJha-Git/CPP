#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
🧾 QUESTION: Get Min from Stack

You are given a series of queries on a stack. Implement a class that supports the following four operations:

1. push(x) – Push integer x onto the stack.
2. pop() – Remove the top element from the stack.
3. peek() – Return the top element of the stack. If the stack is empty, return -1.
4. getMin() – Retrieve the minimum element in the stack in O(1) time. If the stack is empty, return -1.

Example Input:
queries = [[1, 2], [1, 3], [3], [2], [4], [1, 1], [4]]

Example Output:
[3, 2, 1]

Explanation:
push(2) → stack: [2], minStack: [2]
push(3) → stack: [2, 3], minStack: [2, 2]
peek()  → 3
pop()   → stack: [2], minStack: [2]
getMin()→ 2
push(1) → stack: [2, 1], minStack: [2, 1]
getMin()→ 1
*/

// ✅ APPROACH:
// Use two stacks:
// 1. mainStack to store all elements
// 2. minStack to track the minimum at every level

class Solution {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    // Constructor
    Solution() {}

    // Add an element to the top of the Stack
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty()) {
            minStack.push(x);
        } else {
            minStack.push(min(x, minStack.top()));
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if (!mainStack.empty()) {
            mainStack.pop();
            minStack.pop();
        }
    }

    // Returns the top element of the Stack
    int peek() {
        if (!mainStack.empty()) {
            return mainStack.top();
        }
        return -1;
    }

    // Returns the minimum element of the Stack
    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        return -1;
    }
};

// 🔍 DRIVER CODE
int main() {
    Solution s;

    // Sample input
    vector<vector<int>> queries = {
        {1, 2},   // push(2)
        {1, 3},   // push(3)
        {3},      // peek()
        {2},      // pop()
        {4},      // getMin()
        {1, 1},   // push(1)
        {4}       // getMin()
    };

    vector<int> output;

    for (auto& q : queries) {
        if (q[0] == 1) {
            s.push(q[1]);
        } else if (q[0] == 2) {
            s.pop();
        } else if (q[0] == 3) {
            output.push_back(s.peek());
        } else if (q[0] == 4) {
            output.push_back(s.getMin());
        }
    }

    // Print output
    for (int val : output) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

/*
📘 OUTPUT:
3 2 1

🧠 CODE EXPLANATION:
- push(x): adds element to mainStack and updates minStack with the current min.
- pop(): removes top element from both stacks if not empty.
- peek(): returns top of mainStack or -1 if empty.
- getMin(): returns top of minStack (current min) or -1 if empty.

✅ Time Complexity: O(1) per operation
✅ Space Complexity: O(n)
*/
