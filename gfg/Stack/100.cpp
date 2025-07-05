// 🧾 Problem: Longest Valid Parentheses

/*
Given a string s containing just '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.

A valid substring has:
1. Every '(' has a matching ')'
2. ')' must come after '('

Examples:

Input: "((()"
Output: 2
Explanation: Longest valid substring is "()"

Input: ")()())"
Output: 4
Explanation: Longest valid substring is "()()"

Input: "())()"
Output: 2
Explanation: Longest valid substring is "()"
*/

// ✅ Approach: Stack-Based
/*
1. Use a stack to store indices of characters.
2. Push -1 initially to act as a base index.
3. Loop through the string:
   - If '(', push index.
   - If ')':
     - Pop the top.
     - If stack not empty, calculate length = i - top of stack.
     - Else, push current index to reset base.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
  public:
    int maxLength(string& s) {
        stack<int> st;
        st.push(-1);  // Base index for first valid substring
        int max_len = 0;

        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(') {
                st.push(i);  // Push index of '('
            } else {
                st.pop();  // Match with previous '('
                if(!st.empty()) {
                    max_len = max(max_len, i - st.top());
                } else {
                    st.push(i);  // Reset base if unmatched ')'
                }
            }
        }
        return max_len;
    }
};

int main() {
    Solution sol;

    string s1 = "((()";
    string s2 = ")()())";
    string s3 = "())()";

    cout << "Input: " << s1 << " → Output: " << sol.maxLength(s1) << endl;  // Output: 2
    cout << "Input: " << s2 << " → Output: " << sol.maxLength(s2) << endl;  // Output: 4
    cout << "Input: " << s3 << " → Output: " << sol.maxLength(s3) << endl;  // Output: 2

    return 0;
}

/*
🧠 Explanation:
- Push -1 to stack to handle base case.
- On '(', store index.
- On ')':
    - Pop last index. If stack is non-empty, calculate length from top.
    - If stack becomes empty, push current index to reset.
    
🕒 Time: O(n)
🗃️ Space: O(n)
*/
