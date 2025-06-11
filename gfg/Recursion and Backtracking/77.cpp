#include <bits/stdc++.h>
using namespace std;

/*
🧠 N-Queen Problem

Difficulty: Hard
----------------
The n-queens puzzle is the problem of placing n queens on an n×n chessboard
such that no two queens can attack each other.

A queen can attack:
- Vertically
- Horizontally
- Diagonally

You need to return all valid placements of queens.

Input:
    - An integer n (1 ≤ n ≤ 10)
Output:
    - A list of vectors, each representing one solution.
      Each vector contains n integers [r1, r2, ..., rn],
      where ri is the row of the queen in the i-th column (1-indexed).

Example:
---------
Input: n = 4
Output:
[
  [2, 4, 1, 3],
  [3, 1, 4, 2]
]

Approach:
----------
We use backtracking:
- Place one queen per column.
- Skip rows and diagonals already used.
- Use sets to track:
    - Used rows
    - Used diagonals (row - col) and (row + col)

Time Complexity: O(n!) worst case
*/

class Solution {
public:
    vector<vector<int>> res;

    // Recursive function to try placing queens
    void solve(int col, int n, vector<int>& queens,
               unordered_set<int>& rows,
               unordered_set<int>& diag1,
               unordered_set<int>& diag2) {
        
        if (col == n) {
            res.push_back(queens);
            return;
        }

        for (int row = 1; row <= n; row++) {
            if (rows.find(row) != rows.end())
                continue;

            int d1 = row - col;
            int d2 = row + col;

            if (diag1.find(d1) != diag1.end() || diag2.find(d2) != diag2.end())
                continue;

            // Place queen
            queens.push_back(row);
            rows.insert(row);
            diag1.insert(d1);
            diag2.insert(d2);

            // Move to next column
            solve(col + 1, n, queens, rows, diag1, diag2);

            // Backtrack
            queens.pop_back();
            rows.erase(row);
            diag1.erase(d1);
            diag2.erase(d2);
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<int> queens;
        unordered_set<int> rows;
        unordered_set<int> diag1;
        unordered_set<int> diag2;

        solve(0, n, queens, rows, diag1, diag2);
        return res;
    }
};

// ✅ Driver Code for Testing
int main() {
    Solution sol;
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    vector<vector<int>> solutions = sol.nQueen(n);

    cout << "\nNumber of solutions: " << solutions.size() << endl;
    for (auto& sol : solutions) {
        for (int i : sol)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

/*
Sample Run:
-----------
Input:
Enter value of n: 4

Output:
Number of solutions: 2
2 4 1 3 
3 1 4 2 
*/
