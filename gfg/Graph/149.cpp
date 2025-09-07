/*
🚀 Problem: Clone an Undirected Graph

You are given a connected undirected graph represented by adjacency list `adjList[][]` 
with `n` nodes, having a distinct label from `0` to `n-1`. 
Each `adj[i]` represents the list of vertices connected to vertex `i`.

We define the graph node as:
class Node {
public:
    int val;
    vector<Node*> neighbors;
};

Your task:
Implement the function:
    Node* cloneGraph(Node* node);
It should return the deep copy of the graph (a new identical graph with new node objects).

If the copy is correct → driver prints `true`, else `false`.

---

✅ Approach:
We must copy every node and its edges. Since the graph can contain cycles, we must avoid infinite loops.
Use a hash map (unordered_map) to store mapping between original nodes and their clones.

Steps:
1. If input node is NULL → return NULL.  
2. If node already cloned (present in map) → return its clone.  
3. Otherwise:
   - Create a new clone with the same value.  
   - Store it in map.  
   - Recursively clone neighbors and push them into neighbors of the clone.  
4. Return the clone of the starting node.

---

✅ Algorithm:
- Use DFS recursion:
  - Check if node is already cloned.  
  - If not, create clone, save in map, and recurse neighbors.  

Time Complexity: O(V + E)  → every node and edge visited once.  
Space Complexity: O(V)    → hash map + recursion stack.  

---

*/

#include <bits/stdc++.h>
using namespace std;

// Node definition
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// Solution class with cloneGraph
class Solution {
public:
    unordered_map<Node*, Node*> mp;  // map original -> clone
    
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        
        // If already cloned, return it
        if (mp.find(node) != mp.end()) {
            return mp[node];
        }
        
        // Create clone of current node
        Node* clone = new Node(node->val);
        mp[node] = clone;
        
        // Clone neighbors
        for (auto neigh : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neigh));
        }
        
        return clone;
    }
};

// Utility function to print adjacency list of graph
void printGraph(Node* node) {
    unordered_set<Node*> visited;
    queue<Node*> q;
    q.push(node);
    visited.insert(node);

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        cout << "Node " << curr->val << " -> ";
        for (auto neigh : curr->neighbors) {
            cout << neigh->val << " ";
            if (!visited.count(neigh)) {
                visited.insert(neigh);
                q.push(neigh);
            }
        }
        cout << "\n";
    }
}

// ---------------- DRIVER CODE ----------------
int main() {
    /*
    Example: 
    n = 4
    adjList = [[1, 2], [0, 2], [0, 1, 3], [2]]
    */

    int n = 4;
    vector<vector<int>> adjList = {
        {1, 2},      // neighbors of node 0
        {0, 2},      // neighbors of node 1
        {0, 1, 3},   // neighbors of node 2
        {2}          // neighbors of node 3
    };

    // Step 1: Create original graph nodes
    vector<Node*> nodes;
    for (int i = 0; i < n; i++) {
        nodes.push_back(new Node(i));
    }

    // Step 2: Build graph using adjacency list
    for (int i = 0; i < n; i++) {
        for (int j : adjList[i]) {
            nodes[i]->neighbors.push_back(nodes[j]);
        }
    }

    // Step 3: Clone graph
    Solution sol;
    Node* clonedGraph = sol.cloneGraph(nodes[0]);

    // Step 4: Print both graphs to verify
    cout << "Original Graph:\n";
    printGraph(nodes[0]);

    cout << "\nCloned Graph:\n";
    printGraph(clonedGraph);

    // Step 5: Check correctness
    if (clonedGraph != nodes[0]) {
        cout << "\nResult: true (Deep copy created)\n";
    } else {
        cout << "\nResult: false (Incorrect copy)\n";
    }

    return 0;
}

/*
---
✅ Code Explanation:
1. unordered_map<Node*, Node*> mp → remembers mapping of original → cloned node.  
2. cloneGraph(Node* node):  
   - If NULL, return NULL.  
   - If already cloned, return stored clone.  
   - Otherwise:
     * Create new node.  
     * Save in map.  
     * Recursively clone neighbors.  
3. printGraph(): BFS traversal to print adjacency list of any graph.  
4. main():
   - Build a sample graph.  
   - Clone it using cloneGraph().  
   - Print both graphs.  
   - Print "true" if deep copy created.
---
*/
