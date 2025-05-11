/*
================================================================================
📝 PROBLEM: Union of Arrays with Duplicates
================================================================================
🔹 Given two arrays `a[]` and `b[]`, return the number of **distinct elements** 
   present in the union of the two arrays.

🔹 Union of two arrays contains all distinct elements from both arrays. 
   Duplicates are counted only once.

--------------------------------------------------------------------------------
📌 Constraints:
- 1 ≤ a.size(), b.size() ≤ 10^6
- 0 ≤ a[i], b[i] ≤ 10^5

--------------------------------------------------------------------------------
📌 Examples:

Input:
a[] = [1, 2, 3, 4, 5]
b[] = [1, 2, 3]

Output: 5
Explanation: Union = {1, 2, 3, 4, 5}

Input:
a[] = [85, 25, 1, 32, 54, 6]
b[] = [85, 2]

Output: 7
Explanation: Union = {85, 25, 1, 32, 54, 6, 2}

================================================================================
💡 APPROACH:
================================================================================
🔸 We use an `unordered_set<int>` to store only unique elements.
🔸 Insert all elements of array `a` into the set.
🔸 Insert all elements of array `b` into the same set.
🔸 The set automatically removes duplicates.
🔸 Return the size of the set which represents the union count.

🔸 Time Complexity: O(n + m)
🔸 Space Complexity: O(n + m)

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> s;

        // Insert elements of array a
        for (int num : a) {
            s.insert(num);
        }

        // Insert elements of array b
        for (int num : b) {
            s.insert(num);
        }

        // Return count of unique elements
        return s.size();
    }
};

// Driver Code (Do not change anything here)
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline after reading t

    while (t--) {
        vector<int> a;
        vector<int> b;

        string input;
        // For array a
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // For array b
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        cout << ob.findUnion(a, b) << endl;
        cout << '~' << endl;
    }

    return 0;
}
