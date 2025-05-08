// 🧾 Problem: Count Pairs with Given Sum
// Difficulty: Easy
// Accuracy: ~50%
// Average Time: 15 minutes

// Statement:
// Given an array arr[] and an integer target, find the total number of pairs in the array that add up to the given target.

// Input: arr[] = [1, 5, 7, -1, 5], target = 6  
// Output: 3  
// Explanation: Pairs with sum 6 are (1, 5), (7, -1), and (1, 5) again due to duplicate 5.

// Input: arr[] = [1, 1, 1, 1], target = 2  
// Output: 6  
// Explanation: 4 elements make 6 pairs: (1,1) six times.

// 💡 Approach to Solve:
// ✅ Efficient Way (Using Hash Map):
// Use a hash map (unordered_map in C++) to store the frequency of each element as you iterate.

// For each element num, check how many times the complement target - num has already appeared.

// This count gets added to the total.

// Then update the frequency of num.

// ⏱ Time Complexity: O(n)
// 📦 Space Complexity: O(n) for the map

// code-

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        unordered_map<int, int> freq;
        int count = 0;
        
        for (int num : arr) {
            int complement = target - num;
            if (freq.find(complement) != freq.end()) {
                count += freq[complement];
            }
            freq[num]++;
        }
        
        return count;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl << "~" << endl;
    }
    return 0;
}


// 🧠 Explanation:
// Input:
// arr = [1, 5, 7, -1, 5], target = 6

// Process:
// Initialize count = 0, freq = {}

// Go through the array:

// num = 1 → complement is 5 → not in map → add 1 to freq

// num = 5 → complement is 1 → in map once → count = 1, freq[5] = 1

// num = 7 → complement is -1 → not in map

// num = -1 → complement is 7 → in map → count = 2, freq[-1] = 1

// num = 5 → complement is 1 → in map → count = 3, freq[5] = 2

// Final count: 3