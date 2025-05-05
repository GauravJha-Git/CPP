// Problem: Search in a Sorted Matrix
// Difficulty: Medium
// Given: A strictly sorted 2D matrix mat[][] of size n x m and a number x.

// In a strictly sorted matrix:

// Each row is sorted in strictly increasing order.

// The first element of the ith row (i ≠ 0) is greater than the last element of the (i-1)th row.

// Task: Determine whether the number x is present in the matrix or not.
// 💡 Approach: Binary Search (Treat matrix as 1D array)
// Since the matrix is strictly sorted, we can virtually flatten the matrix and apply binary search on the range 0 to n*m - 1.

// To access a value at a virtual index mid in the matrix:

// row = mid / m

// col = mid % m

// So, mat[row][col] gives the value at that position.

// 🔁 Time Complexity: O(log(n * m))
// 📦 Space Complexity: O(1)
// code-
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low = 0, high = n * m - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m;
            int col = mid % m;
            
            if (mat[row][col] == x) {
                return true;
            } else if (mat[row][col] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return false;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~\n";
    }
    return 0;
}