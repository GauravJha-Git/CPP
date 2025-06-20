/*
=========================================
 Tree Boundary Traversal
=========================================

❓ Question:
Given a binary tree, return its boundary traversal in anti-clockwise direction starting from the root.

The boundary includes:
1. Left Boundary (excluding leaves)
2. All Leaf Nodes (left to right)
3. Right Boundary (excluding leaves, reversed)

🧠 Approach:
1. Add the root node if it's not a leaf.
2. Traverse and collect nodes on the left boundary.
3. Traverse and collect all the leaf nodes.
4. Traverse and collect nodes on the right boundary, then reverse them.
5. Combine all the above to get the final result.

🔧 Helper functions:
- isLeaf(node): Check if a node is a leaf.
- addLeftBoundary(node, res): Add left boundary (non-leaf nodes).
- addLeaves(node, res): Add all leaf nodes in left-to-right order.
- addRightBoundary(node, res): Add right boundary (non-leaf nodes in reverse order).

📌 Constraints:
1 ≤ number of nodes ≤ 10^5
1 ≤ node->data ≤ 10^5
*/

/* Tree Node definition */
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

/* Solution Class */
class Solution {
  public:

    // Check if a node is a leaf node
    bool isLeaf(Node* node) {
        return node->left == NULL && node->right == NULL;
    }

    // Add the left boundary excluding leaf nodes
    void addLeftBoundary(Node* node, vector<int>& res) {
        Node* curr = node->left;
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    // Add all the leaf nodes in the tree (in left-to-right order)
    void addLeaves(Node* node, vector<int>& res) {
        if (!node) return;
        if (isLeaf(node)) {
            res.push_back(node->data);
            return;
        }
        addLeaves(node->left, res);
        addLeaves(node->right, res);
    }

    // Add the right boundary excluding leaf nodes, in reverse order
    void addRightBoundary(Node* node, vector<int>& res) {
        Node* curr = node->right;
        vector<int> temp;
        while (curr) {
            if (!isLeaf(curr)) temp.push_back(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        reverse(temp.begin(), temp.end());
        for (int val : temp) res.push_back(val);
    }

    // Main function to perform boundary traversal
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if (!root) return res;

        if (!isLeaf(root)) res.push_back(root->data); // add root only if not a leaf

        addLeftBoundary(root, res);  // left boundary
        addLeaves(root, res);        // leaf nodes
        addRightBoundary(root, res); // right boundary

        return res;
    }
};

/* Example usage to test in main() */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    Solution obj;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = obj.boundaryTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}

/*
🧪 Output:
1 2 4 8 9 6 7 3
*/
