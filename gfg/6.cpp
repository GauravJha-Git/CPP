// You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 

// Note: The answer should be returned in an increasing format.

// Examples:

// Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
// Output: [5, 6]
// Explanation: 5 and 6 occur more n/3 times.
// SOLUTION-
// This problem is a variation of the Boyer-Moore Majority Vote algorithm where we need to find elements that appear more than ⌊n/3⌋ times in the given array. Since at most two elements can have a frequency greater than n/3, we can solve this in O(n) time and O(1) space using a two-pass approach.

// Approach:
// First Pass (Voting Phase): Use two candidate variables and their respective counters to find the potential majority elements.

// Second Pass (Validation Phase): Count the occurrences of the candidates and return only those that appear more than ⌊n/3⌋ times.

// Edge Cases
// ✅ Empty array → []
// ✅ No majority elements → Returns []
// ✅ Only one majority element → Returns [x]
// ✅ Multiple majority elements → Returns sorted list [x, y]

// code-
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};

        int count1 = 0, count2 = 0, candidate1 = -1, candidate2 = -1;

        // Step 1: Finding potential candidates
        for (int num : arr) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Step 2: Count occurrences of candidates
        count1 = 0;
        count2 = 0;
        for (int num : arr) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        // Step 3: Check if they appear more than n/3 times
        vector<int> result;
        if (count1 > n / 3) result.push_back(candidate1);
        if (count2 > n / 3) result.push_back(candidate2);

        sort(result.begin(), result.end());  // Sort to return in increasing order
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
