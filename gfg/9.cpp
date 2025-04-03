// Given an array arr[] denoting heights of N towers and a positive integer K.

// For each tower, you must perform exactly one of the following operations exactly once.

// Increase the height of the tower by K
// Decrease the height of the tower by K
// Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

// You can find a slight modification of the problem here.
// Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.

// Examples :

// Input: k = 2, arr[] = {1, 5, 8, 10}
// Output: 5

// APPROACH-



// 1. **Sort the Array**: Sorting helps us easily find the minimum and maximum heights after modifications.
// 2. **Modify Heights**:
//    - The smallest tower (`arr[0]`) can be increased by \( K \).
//    - The tallest tower (`arr[N-1]`) can be decreased by \( K \).
// 3. **Iterate and Find the Best Combination**:
//    - The minimum height will be the **smallest** among \( arr[0] + K \) and \( arr[i] - K \).
//    - The maximum height will be the **largest** among \( arr[N-1] - K \) and \( arr[i-1] + K \).
//    - We calculate the difference for each modification and keep track of the minimum possible difference.


// ### **Explanation**
// 1. **Sorting**: The array is sorted to consider possible minimum and maximum values efficiently.
// 2. **Initialization**: We start with the initial difference between the maximum and minimum elements.
// 3. **Iterate Through the Array**:
//    - We compute the possible new minimum and maximum values for each modification.
//    - We update the minimum difference (`ans`) accordingly.
// 4. **Edge Case Handling**: If reducing height results in a negative value, we skip that operation.

// code-

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0; // If there's only one tower, no difference
        
        sort(arr.begin(), arr.end()); // Step 1: Sort the array

        int ans = arr[n - 1] - arr[0]; // Initial max difference

        for (int i = 1; i < n; i++) { 
            if (arr[i] - k < 0) continue; // Ignore negative heights

            int min_height = min(arr[0] + k, arr[i] - k);
            int max_height = max(arr[n - 1] - k, arr[i - 1] + k);

            ans = min(ans, max_height - min_height);
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
        cout << '~' << endl;
    }
    return 0;
}
