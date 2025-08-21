/*
📌 Question:
Given a connected undirected graph containing V vertices, represented by a 2-d adjacency list adj[][],
where each adj[i] represents the list of vertices connected to vertex i.
Perform a Breadth First Search (BFS) traversal starting from vertex 0, visiting vertices from left to right 
according to the given adjacency list, and return a list containing the BFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list.

---

🔹 Example 1:
Input: adj = [[2, 3, 1], [0], [0, 4], [0], [2]]
Output: 0 2 3 1 4

Explanation:
Start from 0 → [0]
Visit neighbors of 0 → [2,3,1] → [0,2,3,1]
Visit 4 (neighbor of 2) → [0,2,3,1,4]

---

🔹 Example 2:
Input: adj = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]
Output: 0 1 2 3 4

---

📌 Approach:
1. Use a queue (FIFO) for BFS traversal.
2. Maintain a visited[] array to avoid revisiting nodes.
3. Start BFS from node 0:
   - Push 0 into queue and mark as visited.
   - While queue is not empty:
        - Pop front node from queue.
        - Add it to result.
        - Traverse all its unvisited neighbors (in given order),
          mark visited, and push into queue.
4. Return the traversal order.

📌 Explanation:
BFS explores vertices level by level.
- From 0, visit all neighbors first.
- Then visit their neighbors.
- Continue until all nodes are visited.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size();                 // number of vertices
        vector<int> ans;                    // BFS result
        vector<bool> visited(V, false);     // visited array
        queue<int> q;                       // queue for BFS

        // Start BFS from vertex 0
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            // Traverse all neighbors of current node
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return ans;
    }
};

// ---------- Driver Code ----------
int main() {
    // Example 1
    vector<vector<int>> adj1 = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    Solution obj1;
    vector<int> res1 = obj1.bfs(adj1);

    cout << "BFS Traversal (Example 1): ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    // Example 2
    vector<vector<int>> adj2 = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};
    Solution obj2;
    vector<int> res2 = obj2.bfs(adj2);

    cout << "BFS Traversal (Example 2): ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}

/*
📌 Code Explanation:
1. vector<bool> visited(V,false) → keeps track of visited vertices.
2. queue<int> q → BFS uses queue to explore nodes in order.
3. Start with 0: mark visited, push into queue.
4. While queue not empty:
   - Pop front → add to result.
   - For each neighbor of node:
       - If not visited → mark visited & push to queue.
5. Return traversal result.

✅ This code is ready to copy and run in VS Code.
*/
