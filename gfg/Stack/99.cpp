/*
🧠 Problem: Valid Bracket Expression

Given a string s composed of characters: '(', ')', '{', '}', '[' and ']',
check whether the string is valid.

✅ A string is valid if:
1. Every opening bracket has a corresponding closing bracket of the same type.
2. Brackets are closed in the correct order.

📌 Examples:
Input: s = "[{()}]"
Output: true

Input: s = "[()()]{}"
Output: true

Input: s = "([]"
Output: false

Input: s = "([{]})"
Output: false

🔒 Constraints:
- 1 <= s.length <= 10^6
- s[i] ∈ {'(', ')', '{', '}', '[', ']'}
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// ✅ Solution class
class Solution {
  public:
    bool isBalanced(string& k) {
        stack<char> st;
        for(char ch : k) {
            if(ch == '(' || ch == '{' || ch == '[') {
                // Push opening brackets
                st.push(ch);
            } else {
                // If closing bracket and stack is empty → invalid
                if(st.empty()) return false;
                char top = st.top();
                // Check for matching pair
                if((ch == ')' && top != '(') ||
                   (ch == '}' && top != '{') ||
                   (ch == ']' && top != '[')) {
                    return false;
                }
                // Pop the matched opening bracket
                st.pop();
            }
        }
        // If stack is empty → all brackets matched
        return st.empty();
    }
};

// ✅ Main function to run and test the code
int main() {
    Solution sol;
    string s;

    cout << "Enter bracket string: ";
    cin >> s;

    if (sol.isBalanced(s)) {
        cout << "Output: true (Balanced)" << endl;
    } else {
        cout << "Output: false (Not Balanced)" << endl;
    }

    return 0;
}
