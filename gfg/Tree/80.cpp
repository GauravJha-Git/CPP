/*
📝 Problem: Level Order Traversal

Given the root of a binary tree, return the level order traversal of its nodes' values 
(i.e., from left to right, level by level).

Examples:
Input: root[] = [1, 2, 3]
Output: [[1], [2, 3]]

Input: root[] = [10, 20, 30, 40, 50]
Output: [[10], [20, 30], [40, 50]]

Constraints:
- 1 ≤ number of nodes ≤ 10^5
- 0 ≤ node->data ≤ 10^9
*/

/*
🔍 Approach:
1. Use a queue to perform Breadth-First Search (BFS).
2. Push the root node into the queue.
3. For each level:
   - Count the number of nodes at this level.
   - Pop those many nodes from the queue and store their values.
   - Push their left and right children into the queue (if exist).
4. Store each level as a vector and add it to the final result.
*/

#include <bits/stdc++.h>
using namespace std;

// Define the binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Solution class with level order function
class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;

            for (int i = 0; i < levelSize; i++) {
                Node* curr = q.front();
                q.pop();

                level.push_back(curr->data);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            result.push_back(level);
        }

        return result;
    }
};

// Helper function to build tree from input vector
Node* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "N") return nullptr;

    Node* root = new Node(stoi(nodes[0]));
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        Node* curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "N") {
            curr->left = new Node(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "N") {
            curr->right = new Node(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Main function to test
int main() {
    // Example: input tree [1, 3, 2, N, N, N, 4, 6, 5]
    vector<string> input = {"1", "3", "2", "N", "N", "N", "4", "6", "5"};
    Node* root = buildTree(input);

    Solution sol;
    vector<vector<int>> res = sol.levelOrder(root);

    // Print result
    for (auto level : res) {
        cout << "[ ";
        for (int val : level) {
            cout << val << " ";
        }
        cout << "]\n";
    }

    return 0;
}
