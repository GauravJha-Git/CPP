#include <bits/stdc++.h>
using namespace std;

/*
Problem: Articulation Points in a Graph

You are given an undirected graph with V vertices and E edges. 
The graph is represented as a 2D array edges[][], where edges[i] = [u, v] 
indicates an undirected edge between vertices u and v.

Task: Return all articulation points (cut vertices) in the graph.
- An articulation point is a vertex whose removal increases the number of connected components.
- If no articulation points exist, return {-1}.
- The graph may be disconnected.

Examples:

Input: V = 5, edges = [[0,1],[1,4],[4,3],[4,2],[2,3]]
Output: [1, 4]

Input: V = 4, edges = [[0,1],[0,2]]
Output: [0]

Constraints: 1 ≤ V, E ≤ 10^4

Approach:
1. Use DFS (Depth First Search) + Tarjan's Algorithm.
2. Maintain:
   - disc[u]: discovery time of vertex u
   - low[u]: lowest discovery time reachable from u's subtree or back edge
   - ap[u]: boolean marker if vertex u is an articulation point
3. Rules to find articulation points:
   - Root node with ≥2 children → articulation point
   - Non-root node u: if any child v has low[v] >= disc[u] → u is articulation point
4. Traverse all connected components since the graph can be disconnected.
5. Collect and return all articulation points, or {-1} if none.
*/

// ---------------- Solution Class ----------------
class Solution {
    void dfs(int u, int parent, vector<int> adj[], vector<int>& disc, vector<int>& low, vector<bool>& ap, int &timer) {
        disc[u] = low[u] = ++timer;
        int children = 0;

        for(int v : adj[u]) {
            if(v == parent) continue;

            if(disc[v] == -1) { // Not visited
                children++;
                dfs(v, u, adj, disc, low, ap, timer);
                low[u] = min(low[u], low[v]);

                // Non-root node articulation point
                if(parent != -1 && low[v] >= disc[u]) ap[u] = true;

                // Root node articulation point
                if(parent == -1 && children > 1) ap[u] = true;
            } else {
                // Back edge
                low[u] = min(low[u], disc[v]);
            }
        }
    }

public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<int> adj[V];
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> disc(V, -1), low(V, -1);
        vector<bool> ap(V, false);
        int timer = 0;

        // Run DFS for all components
        for(int i = 0; i < V; i++) {
            if(disc[i] == -1) {
                dfs(i, -1, adj, disc, low, ap, timer);
            }
        }

        // Collect articulation points
        vector<int> result;
        for(int i = 0; i < V; i++) {
            if(ap[i]) result.push_back(i);
        }

        if(result.empty()) return {-1};
        return result;
    }
};

// ---------------- Main Function ----------------
int main() {
    Solution sol;

    // Example 1
    int V1 = 5;
    vector<vector<int>> edges1 = {{0,1}, {1,4}, {4,3}, {4,2}, {2,3}};
    vector<int> res1 = sol.articulationPoints(V1, edges1);
    cout << "Articulation Points: ";
    for(int x : res1) cout << x << " ";
    cout << endl;

    // Example 2
    int V2 = 4;
    vector<vector<int>> edges2 = {{0,1}, {0,2}};
    vector<int> res2 = sol.articulationPoints(V2, edges2);
    cout << "Articulation Points: ";
    for(int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}

/*
Code Explanation:
1. adj[]: adjacency list for fast traversal.
2. disc[u]: stores discovery time when u is first visited.
3. low[u]: lowest discovery time reachable from u (back edges included).
4. dfs() updates disc and low, checks articulation points:
   - Root node: children > 1 → articulation point
   - Non-root: low[v] >= disc[u] → articulation point
5. Result stores all articulation points; if empty returns {-1}.
6. Complexity: O(V + E) time, O(V + E) space.
*/
