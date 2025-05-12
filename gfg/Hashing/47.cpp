/*
🧾 Problem: Longest Consecutive Subsequence

Given an array arr[] of non-negative integers. Find the length of the longest
sub-sequence such that elements in the subsequence are consecutive integers,
the consecutive numbers can be in any order.

🔹Examples:

Input:  arr[] = [2, 6, 1, 9, 4, 5, 3]
Output: 6
Explanation: 1, 2, 3, 4, 5, 6

Input:  arr[] = [1, 9, 3, 10, 4, 20, 2]
Output: 4
Explanation: 1, 2, 3, 4

Input:  arr[] = [15, 13, 12, 14, 11, 10, 9]
Output: 7
Explanation: 9, 10, 11, 12, 13, 14, 15

🔹Constraints:
1 <= arr.size() <= 10^5
0 <= arr[i] <= 10^5

✅ Approach:
- Use an unordered_set to store all elements
- For each number, if it's the start of a sequence (i.e., num - 1 not in set),
  check how long the sequence continues
- Track the longest length
- Time: O(n), Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        int maxLen = 0;

        for (int num : arr) {
            // Only check for the start of a sequence
            if (s.find(num - 1) == s.end()) {
                int currentNum = num;
                int length = 1;

                while (s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    length++;
                }

                maxLen = max(maxLen, length);
            }
        }

        return maxLen;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read array from single line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

