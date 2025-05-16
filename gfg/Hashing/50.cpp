// Problem: Count Subarrays with Given XOR
// Difficulty: Medium
// Description:
// Given an array of integers arr[] and a number k,
// count the number of subarrays having XOR of their elements as k.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        int xorVal = 0;
        long count = 0;

        for (int i = 0; i < arr.size(); i++) {
            xorVal ^= arr[i];

            // Case 1: XOR from start to current index is equal to k
            if (xorVal == k) {
                count++;
            }

            // Case 2: Check if there exists a prefix XOR that gives XOR == k
            if (freq.find(xorVal ^ k) != freq.end()) {
                count += freq[xorVal ^ k];
            }

            // Update frequency of current prefix XOR
            freq[xorVal]++;
        }

        return count;
    }
};

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }

    return 0;
}
