// ✅ Question: Set Matrix Zeroes
// You are given a 2D matrix mat[][] of size n × m. The task is to modify the matrix such that if mat[i][j] is 0, then all elements in the i-th row and j-th column are set to 0. You must do this in-place with constant space complexity.

// 🧠 Approach (Constant Space)
// Use the first row and column as markers:

// If mat[i][j] == 0, set mat[i][0] = 0 and mat[0][j] = 0.

// These will act as flags to mark the entire i-th row and j-th column for zeroing.

// Check separately if the first row or first column originally had any zeros (so we can zero them at the end if needed).

// Traverse the matrix again (excluding first row and column), and if either mat[i][0] == 0 or mat[0][j] == 0, set mat[i][j] = 0.

// Finally, if the first row or column had zero, update them too.

// ✅ Time & Space Complexity:
// Time Complexity: O(n × m)

// Space Complexity: O(1) (in-place, using matrix as flags)

// code-
// Problem: Set Matrix Zeroes
// Approach: In-place with O(1) space using first row and column as flags

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        bool firstRowZero = false, firstColZero = false;

        // Check if first row has any zero
        for (int j = 0; j < m; j++) {
            if (mat[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Check if first column has any zero
        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Use first row and column to mark zeros
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        // Set zeros based on flags
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        // Zero out the first row if needed
        if (firstRowZero) {
            for (int j = 0; j < m; j++) {
                mat[0][j] = 0;
            }
        }

        // Zero out the first column if needed
        if (firstColZero) {
            for (int i = 0; i < n; i++) {
                mat[i][0] = 0;
            }
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~" << "\n";
    }
    return 0;
}
