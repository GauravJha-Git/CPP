// 📘 Problem: Postfix Evaluation
// Difficulty: Medium
// You are given an array of strings `arr[]` that represents a valid arithmetic expression 
// written in Reverse Polish Notation (Postfix Notation).
// Evaluate the expression and return the final result as an integer.

// ✅ Input:
// - A vector of strings `arr[]` of size `n (1 <= n <= 10^5)`
// - Each element is either:
//    - A valid integer in range [-10^4, 10^4]
//    - Or one of the operators: "+", "-", "*", "/"

// ✅ Output:
// - Return an integer — the result of evaluating the postfix expression.

// 🧠 Approach:
// - Use a stack to store operands.
// - Traverse the array:
//   - If token is a number → push to stack.
//   - If token is an operator → pop two operands, perform operation, push result.
// - The last item in the stack is the final result.

// 📌 Notes:
// - Division should truncate towards zero.

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> st;

        for (string& token : arr) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int result;

                if (token == "+") result = a + b;
                else if (token == "-") result = a - b;
                else if (token == "*") result = a * b;
                else result = a / b;  // integer division

                st.push(result);
            } else {
                st.push(stoi(token)); // convert string to int
            }
        }

        return st.top(); // final result
    }
};

// 🧪 Example usage:
int main() {
    Solution sol;

    vector<string> expr1 = {"2", "3", "1", "*", "+", "9", "-"};
    cout << "Output 1: " << sol.evaluate(expr1) << endl; // Expected: -4

    vector<string> expr2 = {"100", "200", "+", "2", "/", "5", "*", "7", "+"};
    cout << "Output 2: " << sol.evaluate(expr2) << endl; // Expected: 757

    return 0;
}

/*
📘 Example 1:
Input: ["2", "3", "1", "*", "+", "9", "-"]
Steps:
  3 * 1 = 3
  2 + 3 = 5
  5 - 9 = -4
Output: -4

📘 Example 2:
Input: ["100", "200", "+", "2", "/", "5", "*", "7", "+"]
Steps:
  100 + 200 = 300
  300 / 2 = 150
  150 * 5 = 750
  750 + 7 = 757
Output: 757

🕒 Time Complexity: O(n)
📦 Space Complexity: O(n)
*/
