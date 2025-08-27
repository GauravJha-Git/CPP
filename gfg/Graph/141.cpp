/*
Problem: Undirected Graph Cycle Detection
Given an undirected graph with V vertices and E edges, determine 
whether the graph contains a cycle. The graph may have multiple components.

Example 1:
Input:  V = 4, E = 4, edges = [[0,1], [0,2], [1,2], [2,3]]
Output: true
Explanation: 1 -> 2 -> 0 -> 1 is a cycle

Example 2:
Input:  V = 4, E = 3, edges = [[0,1], [1,2], [2,3]]
Output: false
Explanation: No cycle exists

Constraints:
1 ≤ V ≤ 10^5
1 ≤ E ≤ 10^5

Approach:
1. Build adjacency list from edge list.
2. Maintain a visited array.
3. For each unvisited node, perform DFS:
   - Mark node as visited
   - For every neighbor:
       - If not visited → DFS on it
       - If already visited and not the parent → cycle found
4. If no cycle found → return false
Time Complexity: O(V + E)
Space Complexity: O(V + E)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // DFS helper function
    bool dfs(int node, int parent, vector<int> adj[], vector<int>& visited) {
        visited[node] = 1;  // mark current as visited
        
        for (auto neigh : adj[node]) {
            if (!visited[neigh]) {
                if (dfs(neigh, node, adj, visited)) return true;
            } 
            else if (neigh != parent) {
                // already visited and not parent => cycle
                return true;
            }
        }
        return false;
    }
  
    // Main function to check cycle
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Visited array
        vector<int> visited(V, 0);
        
        // Check all components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited)) return true;
            }
        }
        return false;
    }
};

// Driver code
int main() {
    Solution obj;
    
    int V1 = 4;
    vector<vector<int>> edges1 = {{0,1}, {0,2}, {1,2}, {2,3}};
    cout << (obj.isCycle(V1, edges1) ? "true" : "false") << endl; // true
    
    int V2 = 4;
    vector<vector<int>> edges2 = {{0,1}, {1,2}, {2,3}};
    cout << (obj.isCycle(V2, edges2) ? "true" : "false") << endl; // false
    
    return 0;
}

/*
Code Explanation:
1. Adjacency List: edges[][] → adj[] for efficient traversal
2. DFS: recursively traverse nodes keeping track of parent
3. Cycle detection: if neighbor visited and not parent → cycle
4. Multiple components: loop through all vertices
*/
