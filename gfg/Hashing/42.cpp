// ✅ Question: Two Sum - Pair with Given Sum
// Difficulty: Easy
// Accuracy: 30.61%
// Average Time: 20 mins
// Points: 2

// You are given an array arr[] of positive integers and an integer target.
// You need to determine if there exist two distinct elements in the array whose sum is equal to the target.
// 🧠 Example
// Input:
// arr[] = [1, 4, 45, 6, 10, 8]
// target = 16
// Output:
// true
// Explanation:
// 6 + 10 = 16 → These elements exist in the array, so the output is true.
// 🔍 Approach
// Use a hash set to store numbers you’ve already seen.

// For every number num in the array, check if target - num exists in the set.

// If yes, return true. If no such pair is found till the end, return false.

// 🧾 Time & Space Complexity
// Time Complexity: O(n)

// Space Complexity: O(n)
// code - 

#include <bits/stdc++.h>
using namespace std;


// User function template for C++
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_set<int> seen;
        for (int num : arr) {
            if (seen.count(target - num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

