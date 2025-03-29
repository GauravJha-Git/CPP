// Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.

// Note: Consider the array as circular.

// Examples :

// Input: arr[] = [1, 2, 3, 4, 5], d = 2
// Output: [3, 4, 5, 1, 2]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n; // Handle cases where d > n

        // Reverse first d elements
        reverse(arr.begin(), arr.begin() + d);

        // Reverse remaining elements
        reverse(arr.begin() + d, arr.end());

        // Reverse entire array
        reverse(arr.begin(), arr.end());
    }
};

// Driver Code
int main() {
    int test_case;
    cin >> test_case;
    while (test_case--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution ob;
        ob.rotateArr(arr, d);

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
