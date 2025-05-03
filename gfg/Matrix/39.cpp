// ✅ Question:
// Search in a Row-wise Sorted Matrix
// Difficulty: Easy

// You're given a 2D matrix mat[][] of size n x m where each row is sorted in increasing order.
// You need to check whether a given integer x is present in the matrix or not.

// 🔷 Constraints:
// Matrix has n rows and m columns.

// Each row is sorted in itself.

// Only rows are sorted, not necessarily columns.

// 📥 Input:
// First line contains an integer t, the number of test cases.

// For each test case:

// First line contains two integers n and m.

// Next n lines contain m integers each.

// Last line contains the integer x to be searched.

// 📤 Output:
// Print true if x is present, otherwise false.

// 💡 Approach:
// Since only each row is sorted, we cannot use the top-right search method (used in row + column sorted matrices).
// Instead, for each row, we perform binary search:

// Loop through all rows.

// For each row, apply binary search for x.

// If found, return true.

// If not found in any row, return false.

// This ensures we efficiently search through each row using O(log m) instead of linear time.

// 🧠 Time Complexity:
// For each test case: O(n * log m)
// Where n = number of rows, m = number of columns.

// code-
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to search a given number in row-wise sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();        // number of rows
        int m = mat[0].size();     // number of columns
        
        // Traverse each row
        for (int i = 0; i < n; ++i) {
            int low = 0, high = m - 1;

            // Binary search in row i
            while (low <= high) {
                int mid = (low + high) / 2;
                if (mat[i][mid] == x) {
                    return true;  // Found the element
                } else if (mat[i][mid] < x) {
                    low = mid + 1;  // Search right
                } else {
                    high = mid - 1; // Search left
                }
            }
        }

        return false; // Not found in any row
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchRowMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~" << "\n";
    }
    return 0;
}