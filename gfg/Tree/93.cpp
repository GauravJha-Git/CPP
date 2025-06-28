/*
💡 Problem:
Given a Binary Search Tree (BST) and two nodes n1 and n2 (as Node pointers), 
find their Lowest Common Ancestor (LCA).

The LCA of two nodes is defined as the lowest node in the BST that has both n1 and n2 as descendants 
(where we allow a node to be a descendant of itself).

🧠 Approach:
Since it's a BST:
- If both n1 and n2 are smaller than root -> LCA lies in the left subtree.
- If both are greater than root -> LCA lies in the right subtree.
- Otherwise, current node is the LCA.

📈 Time Complexity: O(h), where h = height of BST (log n for balanced tree, n for skewed)
*/

#include <iostream>
using namespace std;

/* 🌳 Tree Node Definition */
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

/* 🔍 Solution Class to Find LCA */
class Solution {
public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if (!root) return NULL;

        // Both nodes are in left subtree
        if (n1->data < root->data && n2->data < root->data)
            return LCA(root->left, n1, n2);

        // Both nodes are in right subtree
        if (n1->data > root->data && n2->data > root->data)
            return LCA(root->right, n1, n2);

        // Split point found — this is the LCA
        return root;
    }
};

/* 🔧 Helper Function to Insert a Node into BST */
Node* insertBST(Node* root, int val) {
    if (!root)
        return new Node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

/* 🔍 Helper Function to Find Node Pointer by Value */
Node* findNode(Node* root, int val) {
    if (!root || root->data == val)
        return root;

    if (val < root->data)
        return findNode(root->left, val);
    else
        return findNode(root->right, val);
}

/* 🚀 Main Function */
int main() {
    Node* root = NULL;

    // 🌲 Create BST: [20, 8, 22, 4, 12, 10, 14]
    int values[] = {20, 8, 22, 4, 12, 10, 14};
    for (int val : values)
        root = insertBST(root, val);

    // 🔍 Nodes to find LCA for
    Node* n1 = findNode(root, 8);
    Node* n2 = findNode(root, 14);

    Solution sol;
    Node* lca = sol.LCA(root, n1, n2);

    cout << "✅ LCA of " << n1->data << " and " << n2->data << " is: " << lca->data << endl;

    return 0;
}
