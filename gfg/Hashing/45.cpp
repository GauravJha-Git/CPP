//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

/*
Problem: 
Given two integer arrays a[] and b[], find their intersection.
The intersection should contain only unique common elements (no duplicates), and order does not matter.

Approach:
1. Use an unordered_set to store unique elements from array a.
2. Traverse array b and check for common elements using the set.
3. Insert common elements into a result set to avoid duplicates.
4. Convert the result set to a vector and return it.

Time Complexity: O(n + m), where n and m are sizes of arrays a and b.
*/

class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        unordered_set<int> setA(a.begin(), a.end());  // Step 1: store unique elements of a
        unordered_set<int> result;                    // Step 2: to store common elements

        for (int num : b) {
            if (setA.count(num)) {                    // Step 3: check if num is in setA
                result.insert(num);                   // Step 4: insert into result (removes duplicates)
            }
        }

        return vector<int>(result.begin(), result.end()); // Step 5: convert set to vector
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1, arr2;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        vector<int> res = ob.intersectionWithDuplicates(arr1, arr2);
        sort(res.begin(), res.end());

        if (res.size() == 0) {
            cout << "[]" << endl;
        } else {
            for (auto it : res)
                cout << it << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
