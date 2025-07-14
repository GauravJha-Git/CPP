/*
✅ Question: Decode the String

You are given an encoded string `s`. The encoding rule is:
    k[encoded_string]
Where the `encoded_string` inside the square brackets is repeated exactly `k` times. The string may be nested.

🔹 Constraints:
- 1 ≤ |s| ≤ 10⁵
- 1 ≤ k ≤ 100
- Encoded string contains only lowercase English letters.

🔸 Examples:
Input:  s = "1[b]"
Output: "b"

Input:  s = "3[b2[ca]]"
Output: "bcacabcacabcaca"
*/

/*
✅ Approach:
We use a stack-based approach to decode nested and repeated patterns.

🔹 Steps:
1. Traverse the string character by character.
2. If it's a digit, accumulate the number (could be multiple digits).
3. If it's '[', push the current string and number to stacks.
4. If it's ']', pop from both stacks and repeat the substring.
5. If it's a letter, append it to the current string.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
  public:
    string decodedString(string &s) {
        stack<string> strStack;
        stack<int> numStack;
        string currStr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // handles multiple digit numbers
            } else if (c == '[') {
                numStack.push(num);
                strStack.push(currStr);
                currStr = "";
                num = 0;
            } else if (c == ']') {
                string temp = currStr;
                currStr = strStack.top();
                strStack.pop();
                int repeat = numStack.top();
                numStack.pop();
                while (repeat--) {
                    currStr += temp;
                }
            } else {
                currStr += c;
            }
        }

        return currStr;
    }
};

// ✅ Main function to test
int main() {
    Solution obj;
    string s1 = "1[b]";
    string s2 = "3[b2[ca]]";
    
    cout << "Decoded string of \"" << s1 << "\": " << obj.decodedString(s1) << endl;
    cout << "Decoded string of \"" << s2 << "\": " << obj.decodedString(s2) << endl;

    return 0;
}

/*
✅ Code Explanation:

- `strStack`: Stack to store previous strings.
- `numStack`: Stack to store numbers (repeat counts).
- `currStr`: Builds the current working string.
- `num`: Temporarily holds numbers as we parse them.

🔹 Example for "3[b2[ca]]":
1. Decode inner: 2[ca] = caca
2. Append with 'b': b + caca = bcaca
3. Repeat 3 times: bcacabcacabcaca
*/
