#include <bits/stdc++.h>
using namespace std;

/*
========================================
📌 Problem Statement
========================================
You are given an undirected, weighted, connected graph with V vertices (0 to V-1) and E edges.  
Each edge is represented as edges[i] = [u, v, w], meaning there is an edge between u and v with weight w.  

You are also given a source vertex src.  
Your task is to find the shortest distance from src to every other vertex and return it as an array dist[],  
where dist[i] is the minimum distance from src to i.  

⚠️ Constraints:
- No negative weights.
- Graph is connected.

========================================
📌 Example
========================================
Input:
V = 3
edges = [[0,1,1], [1,2,3], [0,2,6]]
src = 2

Output:
[4, 3, 0]

Explanation:
- Distance from 2 → 0 = 4 (via 2 → 1 → 0)
- Distance from 2 → 1 = 3 (via 2 → 1)
- Distance from 2 → 2 = 0

========================================
📌 Approach
========================================
We use Dijkstra’s Algorithm with a priority queue:

1. Convert edges into an adjacency list.
2. Initialize all distances as infinity, except dist[src] = 0.
3. Use a min-heap (priority queue) to always process the node with the smallest current distance.
4. Relax edges:
   If dist[u] + w < dist[v], update dist[v] and push (dist[v], v) into pq.
5. Continue until pq is empty.
6. Return dist[].

Time Complexity: O((V+E) log V)

========================================
*/

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // undirected graph
        }

        // Step 2: Initialize distances
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Step 3: Min-heap priority queue (distance, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        // Step 4: Process the graph
        while(!pq.empty()){
            auto [d, u] = pq.top(); pq.pop();

            if(d > dist[u]) continue; // skip outdated entries

            for(auto &[v, w] : adj[u]){
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};

// ========================================
// 📌 Main Function (Driver Code)
// ========================================
int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0,1,4}, {0,2,8}, {1,4,6}, {2,3,2}, {3,4,10}
    };
    int src = 0;

    Solution sol;
    vector<int> result = sol.dijkstra(V, edges, src);

    cout << "Shortest distances from src " << src << ":\n";
    for(int d : result) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
