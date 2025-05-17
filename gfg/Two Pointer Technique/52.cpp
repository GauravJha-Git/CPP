#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Count the number of pairs in an array whose sum is strictly less than a given target.

Approach:
1. Sort the array.
2. Use two pointers: one at the start (i), one at the end (j).
3. While i < j:
   - If arr[i] + arr[j] < target:
       * All elements between i and j paired with arr[i] satisfy the condition.
       * Add (j - i) to count.
       * Move i forward to check next element.
   - Else:
       * Decrement j to try smaller sum.
4. Return the count.
*/

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());  // Step 1: sort the array
        
        int count = 0;
        int i = 0, j = arr.size() - 1;
        
        // Step 2 & 3: two pointer technique
        while (i < j) {
            if (arr[i] + arr[j] < target) {
                count += (j - i);
                i++;
            } else {
                j--;
            }
        }
        
        return count;
    }
};

// Driver code to test the solution
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
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
