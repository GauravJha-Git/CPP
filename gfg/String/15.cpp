// Add Binary Strings
// Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
// Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

// Input: s1 = "1101", s2 = "111"
// Output: 10100
// Explanation:
//  1101
// + 111
// 10100

// code-

#include <bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        int i = s1.length() - 1;
        int j = s2.length() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += s1[i--] - '0';
            if (j >= 0) sum += s2[j--] - '0';

            result += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());

        // Remove leading zeros
        int pos = result.find_first_not_of('0');
        if (pos != string::npos) {
            return result.substr(pos);
        } else {
            return "0";
        }
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}



