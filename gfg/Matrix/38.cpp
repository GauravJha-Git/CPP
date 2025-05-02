// Search in a Row-Column sorted matrix
// Difficulty: EasyAccuracy: 41.62%Submissions: 172K+Points: 2Average Time: 15m
// Given a 2D integer matrix mat[][] of size n x m, where every row and column is sorted in increasing order and a number x, the task is to find whether element x is present in the matrix.

// Examples:

// Input: mat[][] = [[3, 30, 38],[20, 52, 54],[35, 60, 69]], x = 62
// Output: false
// Explanation: 62 is not present in the matrix, so output is false.
// Input: mat[][] = [[18, 21, 27],[38, 55, 67]], x = 55
// Output: true
// Explanation: 55 is present in the matrix.

// To find whether a number x is present in a sorted 2D matrix where each row and column is sorted in increasing order, we can use an efficient approach known as the staircase search. This approach works in O(n + m) time complexity.

// Algorithm:
// Start from the top-right corner of the matrix.

// Compare the current element with x:

// If it's equal, return true.

// If it's greater than x, move left (i.e., j--).

// If it's less than x, move down (i.e., i++).

// If you go out of bounds, return false.

// code -
#include <bits/stdc++.h>
using namespace std;




class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();

        int i = 0, j = m - 1;

        while (i < n && j >= 0) {
            if (mat[i][j] == x)
                return true;
            else if (mat[i][j] > x)
                j--;
            else
                i++;
        }

        return false;
    }
};


int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

