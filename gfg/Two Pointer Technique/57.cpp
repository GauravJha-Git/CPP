#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Problem:
Given an integer array arr[] and a number k, find the number of distinct elements 
in every window of size k in the array.

Approach:
- Use a sliding window of size k.
- Use a hash map to count the frequency of each element in the window.
- For each window:
  1. Remove the element going out (reduce its count or erase).
  2. Add the new incoming element.
  3. The number of distinct elements is the size of the map.

Time Complexity: O(n)
Space Complexity: O(k)
*/

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int, int> freq;  // Map to store frequency of elements
        vector<int> result;            // To store count of distinct elements

        // First window
        for (int i = 0; i < k; ++i) {
            freq[arr[i]]++;
        }
        result.push_back(freq.size());

        // Remaining windows
        for (int i = k; i < arr.size(); ++i) {
            // Remove the element going out of the window
            freq[arr[i - k]]--;
            if (freq[arr[i - k]] == 0) {
                freq.erase(arr[i - k]);
            }

            // Add the new element coming into the window
            freq[arr[i]]++;

            // Store the count of distinct elements
            result.push_back(freq.size());
        }

        return result;
    }
};

// Example main function (you said don’t change this)
int main() {
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;

    Solution obj;
    vector<int> res = obj.countDistinct(arr, k);

    for (int x : res) {
        cout << x << " ";
    }
    return 0;
}
