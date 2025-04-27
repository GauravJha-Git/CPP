// Number of occurrence
// Difficulty: EasyAccuracy: 59.34%Submissions: 322K+Points: 2Average Time: 20m
// Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

// Examples :

// Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
// Output: 4


// Explanation: target = 2 occurs 4 times in the given array so the output is 4.

// Since the array is sorted, we can use binary search to find:

// The first occurrence of the target.

// The last occurrence of the target.

// Then, the number of occurrences = (last index - first index + 1).

// code-
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        
        // Find first occurrence
        int low = 0, high = n - 1, first = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == target) {
                first = mid;
                high = mid - 1; // go left
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        // Find last occurrence
        low = 0, high = n - 1;
        int last = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == target) {
                last = mid;
                low = mid + 1; // go right
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        if (first == -1) return 0; // target not found
        
        return last - first + 1;
    }
};


int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

