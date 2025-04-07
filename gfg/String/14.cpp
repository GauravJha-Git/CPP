// Implement Atoi
// Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. Refer the below steps to know about atoi() function.

// Cases for atoi() conversion:

// Skip any leading whitespaces.
// Check for a sign (‘+’ or ‘-‘), default to positive if no sign is present.
// Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. If no digits are present, return 0.
// If the integer is greater than 231 – 1, then return 231 – 1 and if the integer is smaller than -231, then return -231.
// Examples:

// Input: s = "-123"
// Output: -123
// Explanation: It is possible to convert -123 into an integer so we returned in the form of an integer
// Input: s = "  -"
// Output: 0
// Explanation: No digits are present, therefore the returned answer is 0.
// code-
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;




class Solution {
  public:
    int myAtoi(char *s) {
        int i = 0;
        int sign = 1;
        long result = 0;

        // 1. Skip leading whitespaces
        while (s[i] == ' ') {
            i++;
        }

        // 2. Check for sign
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Convert characters to integer
        while (s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            result = result * 10 + digit;

            // 4. Check for overflow
            if (sign == 1 && result > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -result < INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign * result;
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
