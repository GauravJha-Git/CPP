/*
Directed Graph Cycle Detection
Difficulty: Medium

Problem:
Given a directed graph with V vertices numbered from 0 to V-1 and E edges, 
check whether it contains any cycle.

The graph is given as a 2D vector edges[][], where each entry edges[i] = [u, v] 
represents a directed edge from vertex u to vertex v.

Examples:
Input: V = 4, edges = [[0,1],[0,2],[1,2],[2,0],[2,3]]
Output: true
Explanation: There is a cycle: 0 → 2 → 0

Input: V = 4, edges = [[0,1],[0,2],[1,2],[2,3]]
Output: false
Explanation: No cycle exists

Constraints:
1 ≤ V, E ≤ 10^5
u ≠ v

Approach (DFS + Recursion Stack):
1. Maintain two arrays:
   - visited[]: marks if a node has been visited.
   - recStack[]: marks if a node is part of the current DFS recursion path.
2. For each unvisited node, run DFS:
   - Mark node visited and add to recursion stack.
   - For all neighbors:
     - If neighbor is unvisited → DFS on neighbor.
     - If neighbor is in recursion stack → cycle detected.
   - Remove node from recursion stack after DFS.
3. Repeat DFS for all unvisited nodes to cover disconnected components.

Time Complexity: O(V + E)
Space Complexity: O(V)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS helper function to detect cycle
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& recStack){
        visited[node] = 1;
        recStack[node] = 1;  // mark in recursion stack
        
        for(int neighbour : adj[node]){
            if(!visited[neighbour] && dfs(neighbour, adj, visited, recStack))
                return true;
            else if(recStack[neighbour])
                return true;
        }
        
        recStack[node] = 0; // remove from recursion stack
        return false;
    }
  
    // Main function to check if the graph has a cycle
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int> visited(V,0);
        vector<int> recStack(V,0);
        
        for(int i = 0; i < V; i++){
            if(!visited[i] && dfs(i, adj, visited, recStack))
                return true;
        }
        
        return false;
    }
};

int main() {
    int V = 4;
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{2,0},{2,3}};

    Solution sol;
    if(sol.isCyclic(V, edges))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
