/*
📌 Problem: Bellman-Ford Algorithm

You are given a weighted graph with V vertices (0 to V-1) and E edges.
Each edge is represented as [u, v, w], meaning there is a directed edge from u → v with weight w.

You are also given a source vertex (src).

Task:
- Compute shortest distance from src to all vertices.
- If a vertex is unreachable, mark it as 1e8 (108 in GFG).
- If the graph contains a negative weight cycle, return [-1].

----------------------------------------------------------
✅ Approach:
1. Initialize distance array with 1e8, dist[src] = 0.
2. Relax all edges (V-1) times.
3. Check once more for negative cycle.
   - If found, return {-1}.
4. Otherwise, return dist[].

----------------------------------------------------------
🔑 Algorithm:
1. dist[] = {1e8,...,1e8}, dist[src] = 0
2. Repeat (V-1) times:
      For each edge (u,v,w):
          If dist[u] + w < dist[v]:
              dist[v] = dist[u] + w
3. For each edge (u,v,w):
      If dist[u] + w < dist[v]:
          return {-1}
4. Return dist[]

----------------------------------------------------------
⏱️ Complexity:
- Time: O(V * E)
- Space: O(V)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        const int INF = 1e8;  
        vector<int> dist(V, INF);
        dist[src] = 0;

        // Step 1: Relax edges (V-1) times
        for (int i = 0; i < V - 1; i++) {
            for (auto &edge : edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Step 2: Check for negative cycle
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                return {-1};  // Negative cycle detected
            }
        }

        return dist;
    }
};

int main() {
    Solution obj;

    // Example 1
    int V1 = 5, src1 = 0;
    vector<vector<int>> edges1 = {{1,3,2}, {4,3,-1}, {2,4,1}, {1,2,1}, {0,1,5}};
    vector<int> ans1 = obj.bellmanFord(V1, edges1, src1);

    cout << "Example 1 Output: ";
    for (int x : ans1) cout << x << " ";
    cout << endl;

    // Example 2
    int V2 = 4, src2 = 0;
    vector<vector<int>> edges2 = {{0,1,4}, {1,2,-6}, {2,3,5}, {3,1,-2}};
    vector<int> ans2 = obj.bellmanFord(V2, edges2, src2);

    cout << "Example 2 Output: ";
    for (int x : ans2) cout << x << " ";
    cout << endl;

    return 0;
}

/*
📖 Code Explanation:
1. dist[src] = 0 → distance from source to itself is 0.
2. Outer loop runs (V-1) times → standard Bellman-Ford relaxation.
3. Each edge (u,v,w) is checked:
   if dist[u] + w < dist[v], update dist[v].
4. After V-1 relaxations, distances are finalized.
5. One extra loop checks for negative cycle:
   - If any distance can still be reduced → return {-1}.
6. Otherwise, return dist[].
*/
