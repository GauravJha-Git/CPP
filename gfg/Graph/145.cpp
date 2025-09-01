/*
📌 Problem: Bridge Edge in a Graph

Given an undirected graph with V vertices (0 to V-1) and E edges, 
and a specific edge (c, d), determine whether this edge is a bridge.

👉 An edge is a bridge if removing it increases the number of connected components.

----------------------------------------------------
Example 1:
Input:
V = 4
edges = [[0,1],[1,2],[2,3]]
c = 1, d = 2

Output: true
Explanation:
Removing edge (1,2) splits graph into {0,1} and {2,3}, so it is a bridge.

----------------------------------------------------
Example 2:
Input:
V = 5
edges = [[0,1],[0,3],[1,2],[2,0],[3,4]]
c = 0, d = 2

Output: false
Explanation:
Even after removing (0,2), graph is still connected via 0→1→2.
So it is not a bridge.

----------------------------------------------------
Constraints:
1 ≤ V, E ≤ 1e5
0 ≤ c, d ≤ V-1

----------------------------------------------------
📌 Approach (Tarjan’s Algorithm):
1. Use DFS to assign:
   - disc[u] = discovery time of node u
   - low[u] = earliest discovered node reachable from u
2. For each edge (u,v):
   - If low[v] > disc[u], then (u,v) is a bridge.
3. Check if given edge (c,d) is a bridge.

Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int timer;  // global timer
    
    // DFS helper
    void dfs(int u, int parent, vector<int> adj[], vector<int>& disc, vector<int>& low, int c, int d, bool &found) {
        disc[u] = low[u] = ++timer;
        
        for (int v : adj[u]) {
            if (v == parent) continue;
            
            if (disc[v] == -1) {
                dfs(v, u, adj, disc, low, c, d, found);
                low[u] = min(low[u], low[v]);
                
                // bridge condition
                if (low[v] > disc[u]) {
                    if ((u == c && v == d) || (u == d && v == c)) {
                        found = true;
                    }
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
  
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<int> adj[V];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> disc(V, -1), low(V, -1);
        timer = 0;
        bool found = false;
        
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                dfs(i, -1, adj, disc, low, c, d, found);
            }
        }
        
        return found;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    int V1 = 4;
    vector<vector<int>> edges1 = {{0,1}, {1,2}, {2,3}};
    int c1 = 1, d1 = 2;
    cout << (sol.isBridge(V1, edges1, c1, d1) ? "true" : "false") << endl;  // expected true
    
    // Test case 2
    int V2 = 5;
    vector<vector<int>> edges2 = {{0,1}, {0,3}, {1,2}, {2,0}, {3,4}};
    int c2 = 0, d2 = 2;
    cout << (sol.isBridge(V2, edges2, c2, d2) ? "true" : "false") << endl;  // expected false
    
    return 0;
}
