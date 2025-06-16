// 📝 Problem: Mirror Tree
// Given a binary tree, convert the binary tree into its mirror tree.
// Mirror of a Binary Tree is another Binary Tree with left and right
// children of all non-leaf nodes interchanged.

// ✅ Approach:
// - Use recursion.
// - For every node, swap the left and right subtrees.
// - Recursively do the same for left and right children.
// - Base case: if node is NULL, return.

// ✅ Time Complexity: O(N) — every node visited once
// ✅ Space Complexity: O(H) — recursion stack (H = height of tree)

#include <iostream>
using namespace std;

// Node structure for binary tree
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // Base Case: If the node is NULL, return.
        if (node == NULL)
            return;

        // Swap left and right child pointers
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;

        // Recursively mirror the left and right subtrees
        mirror(node->left);
        mirror(node->right);
    }
};

// 🔁 Helper function to print inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// 🧪 Sample usage
int main() {
    /*
           1
         /   \
        2     3
       / \
      4   5

    After mirror:
           1
         /   \
        3     2
             / \
            5   4
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution obj;
    cout << "Inorder before mirror: ";
    inorder(root);
    cout << endl;

    obj.mirror(root);

    cout << "Inorder after mirror: ";
    inorder(root);
    cout << endl;

    return 0;
}
