#include <bits/stdc++.h>
using namespace std;

/*
Question:
-----------
You are given a matrix mat of size n x m where each cell can have one of three values:
0 → Empty cell
1 → Fresh orange
2 → Rotten orange

A rotten orange can rot its adjacent fresh oranges (up, down, left, right) in 1 unit time.
We need to determine the minimum time required to rot all oranges, or return -1 if impossible.
*/

/*
Approach:
-----------
We solve this using BFS (multi-source):
1. Push all rotten oranges into a queue with time=0.
2. Count fresh oranges.
3. Process queue:
   - For each rotten orange, rot its fresh neighbors.
   - Push them into the queue with time+1.
4. After BFS:
   - If fresh oranges remain → return -1.
   - Otherwise → return maximum time.
*/

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<pair<int,int>, int>> q;  // {{row, col}, time}
        int fresh = 0;
        
        // Step 1: Add rotten oranges and count fresh
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 2){
                    q.push({{i,j}, 0});
                } else if(mat[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        int time = 0;
        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};
        
        // Step 2: BFS
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int t = it.second;
            time = max(time, t);
            
            for(int k=0; k<4; k++){
                int nr = r + drow[k];
                int nc = c + dcol[k];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc] == 1){
                    mat[nr][nc] = 2;   // rot it
                    fresh--;
                    q.push({{nr,nc}, t+1});
                }
            }
        }
        
        // Step 3: Final check
        if(fresh > 0) return -1;
        return time;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat1 = {{0,1,2},{0,1,2},{2,1,1}};
    cout << "Output 1: " << sol.orangesRotting(mat1) << endl;  // Expected: 1

    vector<vector<int>> mat2 = {{2,2,0,1}};
    cout << "Output 2: " << sol.orangesRotting(mat2) << endl;  // Expected: -1

    vector<vector<int>> mat3 = {{2,2,2},{0,2,0}};
    cout << "Output 3: " << sol.orangesRotting(mat3) << endl;  // Expected: 0

    return 0;
}

/*
Code Explanation:
-------------------
- We use queue<pair<pair<int,int>,int>> to store {position, time}.
- Initialize queue with all rotten oranges.
- BFS rots fresh neighbors, decreases fresh count, and pushes them with +1 time.
- Track max time using `time = max(time, t)`.
- If fresh > 0 at the end → not all oranges can rot → return -1.
- Else return time.
*/
