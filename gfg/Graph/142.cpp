#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find the Number of Islands

Given a grid of size n x m consisting of 'L' (Land) and 'W' (Water).
An island is formed by connected lands in 8 directions (horizontal, vertical, diagonal).
Count the number of islands in the grid.

Example:
Input:
[['L','L','W','W','W'],
 ['W','L','W','W','L'],
 ['L','W','W','L','L'],
 ['W','W','W','W','W'],
 ['L','W','L','L','W']]
Output: 4
*/

class Solution {
public:
    int n, m;
    // Directions for 8 neighbors
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};

    // DFS function to mark connected lands
    void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
        visited[x][y] = true;
        for(int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m 
               && grid[nx][ny] == 'L' && !visited[nx][ny]) {
                dfs(nx, ny, grid, visited);
            }
        }
    }

    // Function to count islands
    int countIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if(n == 0) return 0;
        m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int islands = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'L' && !visited[i][j]) {
                    islands++;
                    dfs(i, j, grid, visited);
                }
            }
        }

        return islands;
    }
};

// Main function to test the solution
int main() {
    vector<vector<char>> grid = {
        {'L','L','W','W','W'},
        {'W','L','W','W','L'},
        {'L','W','W','L','L'},
        {'W','W','W','W','W'},
        {'L','W','L','L','W'}
    };

    Solution sol;
    cout << "Number of islands: " << sol.countIslands(grid) << endl;

    return 0;
}

/*
Explanation:
1. dx and dy arrays define 8 directions to move in the grid.
2. dfs function visits all connected lands from a starting land cell.
3. countIslands iterates the grid, starts dfs for every unvisited land, and increments the island count.
4. Time Complexity: O(n*m), each cell is visited once.
5. Space Complexity: O(n*m) for visited array + recursion stack.
*/
