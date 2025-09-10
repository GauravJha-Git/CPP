/*
❓ QUESTION: Floyd–Warshall Algorithm

You are given a weighted directed graph, represented by an adjacency matrix `dist[][]` of size n x n, 
where dist[i][j] represents the weight of the edge from node i to node j. 

- If there is no direct edge, dist[i][j] is set to a large value (e.g., 100000000) representing infinity.
- The graph may contain negative edge weights, but it does not contain negative weight cycles.

Your task is to find the shortest distance between every pair of nodes (i, j) in the graph.
Modify the matrix in-place.

---

🔑 APPROACH:

We use the Floyd–Warshall algorithm (All Pairs Shortest Path):

1. Consider every node k as an intermediate node.
2. For every pair (i, j), check if the path i -> k -> j is shorter than the current i -> j.
3. If yes, update dist[i][j].
4. Repeat for all k.

---

🧮 ALGORITHM:

for k = 0 to n-1:
    for i = 0 to n-1:
        for j = 0 to n-1:
            if dist[i][k] != INF and dist[k][j] != INF:
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

⚡ Complexity:
- Time: O(n^3)
- Space: O(1) (in-place)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        int INF = 100000000; // Use input's infinity
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        long long sum = (long long)dist[i][k] + (long long)dist[k][j];
                        if (sum < dist[i][j]) dist[i][j] = (int)sum;
                    }
                }
            }
        }
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    Solution sol;
    int t; // number of test cases
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> dist(n, vector<int>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> dist[i][j];
        
        sol.floydWarshall(dist);

        cout << "Shortest distance matrix:\n";
        for(auto &row : dist) {
            for(auto &val : row) cout << val << " ";
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}

/*
📝 CODE EXPLANATION:

1. Input:
   - Number of test cases `t`.
   - For each test case, size `n` and adjacency matrix `dist[][]`.
   - Infinity is represented by a large number like 100000000.

2. Core logic:
   - Triple nested loop (k, i, j) considers each node `k` as an intermediate.
   - Only add if dist[i][k] and dist[k][j] are not infinity.
   - Use long long for addition to prevent integer overflow.
   - Update dist[i][j] if a shorter path is found.

3. Output:
   - Updated shortest distance matrix for each test case.
*/
