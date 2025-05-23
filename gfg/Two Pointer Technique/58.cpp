/*
📘 Question:
Given a string s, find the length of the longest substring which contains all distinct characters.

🔒 Constraints:
- 1 <= s.size() <= 3 * 10^4
- All characters are lowercase English letters.

✅ Examples:
Input: s = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest substring with all unique characters.

Input: s = "aaa"
Output: 1
Explanation: The longest substring is "a".

Input: s = "abcdefabcbb"
Output: 6
Explanation: "abcdef" is the longest substring.

------------------------------------

💡 Approach:
Use the sliding window technique with a hash map to keep track of last seen positions of characters.
Move the window forward whenever you see a duplicate character.

🧠 Explanation:
- Use two pointers: `start` and `end` to define a window.
- Use a hash map to store the last seen index of each character.
- If a duplicate character is found inside the window, move `start` to `lastSeen[char] + 1`.
- Update the max length of the window as you go.

------------------------------------

👨‍💻 Code:
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        unordered_map<char, int> lastSeen;
        int maxLen = 0, start = 0;

        for (int end = 0; end < s.size(); end++) {
            char current = s[end];

            // If the character is repeated and inside the window
            if (lastSeen.find(current) != lastSeen.end() && lastSeen[current] >= start) {
                start = lastSeen[current] + 1;
            }

            lastSeen[current] = end;
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};

/*
🧪 Optional: Sample main function to test
*/
int main() {
    Solution obj;
    string s;
    cout << "Enter string: ";
    cin >> s;

    int result = obj.longestUniqueSubstr(s);
    cout << "Length of longest substring with all distinct characters: " << result << endl;

    return 0;
}
