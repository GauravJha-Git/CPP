/*
📌 Question: Subarrays with Sum K
Difficulty: Medium

📝 Given:
An unsorted array of integers `arr` and an integer `k`.

🎯 Task:
Find the number of subarrays that have a sum exactly equal to `k`.

🔍 Examples:

Input:
arr = [10, 2, -2, -20, 10], k = -10
Output: 3
Explanation: Subarrays with sum -10 are:
  → [10, 2, -2, -20]
  → [2, -2, -20, 10]
  → [-20, 10]

Input:
arr = [1, 3, 5], k = 0
Output: 0

--------------------------------------------

🧠 Approach: Prefix Sum + Hash Map

We calculate the running sum (prefix sum) while traversing the array.
We use an unordered_map to store the frequency of prefix sums seen so far.

Key Idea:
If current prefix sum is `prefixSum`, and `prefixSum - k` exists in the map,
then we found a subarray ending at current index with sum `k`.

We initialize the map with {0:1} to handle cases where subarray starts from index 0.

--------------------------------------------

🧑‍💻 Time Complexity: O(n)
🧠 Space Complexity: O(n)

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> prefixSumCount;
        int prefixSum = 0, count = 0;

        prefixSumCount[0] = 1; // Handles subarrays starting from index 0

        for (int i = 0; i < arr.size(); ++i) {
            prefixSum += arr[i];

            // If (prefixSum - k) is in the map, add its frequency to count
            if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[prefixSum - k];
            }

            // Update frequency of the current prefix sum
            prefixSumCount[prefixSum]++;
        }

        return count;
    }
};


// Main function (DO NOT MODIFY)
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}
