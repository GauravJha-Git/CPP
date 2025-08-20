/*
====================================================
📌 Question: DFS of Graph
====================================================
Given a connected undirected graph containing V vertices represented 
by a 2D adjacency list adj[][], where each adj[i] represents the list 
of vertices connected to vertex i.

Perform a Depth First Search (DFS) traversal starting from vertex 0, 
visiting vertices in the same order as given in the adjacency list.

Return the list containing the DFS traversal of the graph.

----------------------------------------------------
Example 1:
Input: adj = [[2, 3, 1], [0], [0, 4], [0], [2]]
Output: 0 2 4 3 1

Explanation:
- Start at 0 → result = [0]
- Visit 2 → result = [0, 2]
- Visit 4 → result = [0, 2, 4]
- Backtrack → visit 3 → result = [0, 2, 4, 3]
- Backtrack → visit 1 → result = [0, 2, 4, 3, 1]

----------------------------------------------------
Example 2:
Input: adj = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]
Output: 0 1 2 3 4
====================================================
*/

/*
====================================================
📌 Approach:
====================================================
1. Create a visited array to keep track of visited nodes.
2. Start DFS from node 0.
3. Mark node as visited and add it to result list.
4. Recursively visit all unvisited neighbors (in adjacency list order).
5. Return the traversal order.
====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive DFS helper function
    void dfsHelper(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& result) {
        visited[node] = 1;            // Mark node as visited
        result.push_back(node);       // Add node to result

        // Traverse all neighbors in given order
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, adj, visited, result);
            }
        }
    }

    // Main DFS function
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();           // Number of vertices
        vector<int> visited(V, 0);    // Visited array
        vector<int> result;           // To store DFS traversal

        dfsHelper(0, adj, visited, result);  // Start DFS from vertex 0
        return result;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> adj1 = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> ans1 = sol.dfs(adj1);
    cout << "DFS Traversal (Example 1): ";
    for (int x : ans1) cout << x << " ";
    cout << endl;

    // Example 2
    vector<vector<int>> adj2 = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};
    vector<int> ans2 = sol.dfs(adj2);
    cout << "DFS Traversal (Example 2): ";
    for (int x : ans2) cout << x << " ";
    cout << endl;

    return 0;
}

/*
====================================================
📌 Explanation of Code:
====================================================
- dfsHelper(node, adj, visited, result): 
  Handles recursion, marks node visited, adds to result, 
  and explores neighbors.

- dfs(adj): 
  Creates visited[] and result[], 
  calls dfsHelper(0, ...) to start DFS from node 0.

- main(): 
  Tests with 2 examples and prints the DFS traversal.

✅ Output:
DFS Traversal (Example 1): 0 2 4 3 1
DFS Traversal (Example 2): 0 1 2 3 4
====================================================
*/
