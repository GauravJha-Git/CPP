/*
---------------------------------------------------------
📌 Problem Statement: Flood Fill Algorithm
---------------------------------------------------------
You are given a 2D grid `image[][]` of size n*m, where each `image[i][j]`
represents the color of a pixel. You are also given a coordinate `(sr, sc)` 
representing the starting pixel, and a new color `newColor`.

Perform a Flood Fill starting from `(sr, sc)`:
- Replace the color of the starting pixel and all 4-directionally connected 
  pixels having the same original color with `newColor`.
- Two pixels are connected if they are adjacent horizontally or vertically.

Return the modified image.

---------------------------------------------------------
📌 Example
Input:
image = [[1, 1, 1, 0],
         [0, 1, 1, 1],
         [1, 0, 1, 1]]
sr = 1, sc = 2, newColor = 2

Output:
[[2, 2, 2, 0],
 [0, 2, 2, 2],
 [1, 0, 2, 2]]

Explanation:
Starting at (1,2) which has color 1, all connected pixels with value 1 are 
updated to 2.

---------------------------------------------------------
📌 Approach
1. Store the original color at (sr, sc).
2. If originalColor == newColor, return the image as is (avoid infinite loop).
3. Use DFS (Depth-First Search):
   - Check if the current pixel is inside bounds and has the original color.
   - Change its color to newColor.
   - Recursively visit 4-connected neighbors (up, down, left, right).

---------------------------------------------------------
📌 Algorithm
1. Start DFS from (sr, sc).
2. If pixel is valid and has originalColor, change to newColor.
3. Recurse in 4 directions.
4. Return modified image.

---------------------------------------------------------
📌 Complexity
- Time: O(n * m), each cell visited at most once.
- Space: O(n * m), recursion stack in worst case.
---------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // DFS helper function
    void dfs(vector<vector<int>>& image, int sr, int sc, int originalColor, int newColor) {
        int n = image.size();
        int m = image[0].size();

        // boundary check + color match check
        if (sr < 0 || sr >= n || sc < 0 || sc >= m || image[sr][sc] != originalColor) 
            return;

        // change the current pixel's color
        image[sr][sc] = newColor;

        // recursive calls in 4 directions
        dfs(image, sr+1, sc, originalColor, newColor); // down
        dfs(image, sr-1, sc, originalColor, newColor); // up
        dfs(image, sr, sc+1, originalColor, newColor); // right
        dfs(image, sr, sc-1, originalColor, newColor); // left
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        if (originalColor == newColor) return image; // avoid infinite recursion
        dfs(image, sr, sc, originalColor, newColor);
        return image;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> image = {
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1}
    };

    int sr = 1, sc = 2, newColor = 2;

    cout << "Original Image:\n";
    for (auto &row : image) {
        for (auto &val : row) cout << val << " ";
        cout << "\n";
    }

    vector<vector<int>> ans = sol.floodFill(image, sr, sc, newColor);

    cout << "\nAfter Flood Fill:\n";
    for (auto &row : ans) {
        for (auto &val : row) cout << val << " ";
        cout << "\n";
    }

    return 0;
}
