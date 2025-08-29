/*
================================================================================
📌 Problem: Topological Sort (Directed Acyclic Graph)

Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges 
represented as a 2D list of edges[][], where each entry edges[i] = [u, v] 
denotes a directed edge u -> v. 

Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of 
vertices such that for every directed edge u -> v, vertex u comes before v in 
the ordering.

Note: As there are multiple Topological orders possible, you may return any of 
them. If your returned Topological sort is correct then the output will be true 
else false.

--------------------------------------------------------------------------------
✅ Example 1:
Input:
V = 4, E = 3
edges = [[3,0], [1,0], [2,0]]

Output (one possible order):
3 1 2 0

Explanation:
- Edges are 3→0, 1→0, 2→0
- So 3,1,2 must come before 0
- Multiple valid answers possible

--------------------------------------------------------------------------------
✅ Example 2:
Input:
V = 6, E = 6
edges = [[1,3], [2,3], [4,1], [4,0], [5,0], [5,2]]

Output (one possible order):
4 5 1 2 0 3

Explanation:
- 4 must come before 1
- 5 must come before 0
- Multiple valid answers exist

--------------------------------------------------------------------------------
🔹 Approach (Kahn’s Algorithm – BFS)
1. Build adjacency list from edges
2. Compute indegree (incoming edges) for every vertex
3. Push vertices with indegree = 0 into queue
4. While queue not empty:
   - Pop node, add it to result
   - For each neighbor: reduce indegree by 1
   - If neighbor’s indegree = 0, push into queue
5. Return result as topological order

--------------------------------------------------------------------------------
⏱️ Complexity Analysis
- Time Complexity: O(V + E) (visit all nodes and edges once)
- Space Complexity: O(V + E) (adjacency list, indegree array, result)
================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Step 1: Create adjacency list
        vector<int> adj[V];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        // Step 2: Calculate indegree
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int nei : adj[i]) {
                indegree[nei]++;
            }
        }

        // Step 3: Push nodes with indegree = 0 into queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // Step 4: BFS
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            // Reduce indegree of neighbors
            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) q.push(nei);
            }
        }

        return topo;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input format:
    // First line: V E
    // Next E lines: u v (edge from u to v)
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    Solution obj;
    vector<int> res = obj.topoSort(V, edges);

    // Print the result
    for (int x : res) cout << x << " ";
    cout << "\n";

    return 0;
}
