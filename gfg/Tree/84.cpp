// Question:
// Given two arrays:
// 1. inorder[] - inorder traversal of a binary tree
// 2. preorder[] - preorder traversal of the same binary tree
// Construct the binary tree and return the root node.
// Then print the postorder traversal of the constructed tree.

// ✅ Approach:
// - In preorder, the first element is the root of the tree.
// - In inorder, elements to the left of the root are in the left subtree,
//   and elements to the right are in the right subtree.
// - Recursively:
//   1. Pick root from preorder.
//   2. Find its index in inorder.
//   3. Build left and right subtrees.
// - After building the tree, do postorder traversal for output.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 🔷 Node structure for the binary tree
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// 🔶 Solution class to build tree and get postorder
class Solution {
public:
    int preIndex = 0;
    unordered_map<int, int> inMap;

    // Recursively builds the binary tree
    Node* buildUtil(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;

        int rootVal = preorder[preIndex++];
        Node* root = new Node(rootVal);

        int inIndex = inMap[rootVal];

        root->left = buildUtil(preorder, inorder, inStart, inIndex - 1);
        root->right = buildUtil(preorder, inorder, inIndex + 1, inEnd);

        return root;
    }

    // Builds tree from inorder and preorder
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        inMap.clear();
        preIndex = 0;

        for (int i = 0; i < inorder.size(); ++i)
            inMap[inorder[i]] = i;

        return buildUtil(preorder, inorder, 0, inorder.size() - 1);
    }

    // Collects postorder traversal
    void postorder(Node* root, vector<int>& result) {
        if (!root) return;
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->data);
    }
};

// 🔸 Driver code
int main() {
    // Example Input
    vector<int> inorder = {3, 1, 4, 0, 2, 5};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};

    // Solution call
    Solution obj;
    Node* root = obj.buildTree(inorder, preorder);

    // Get postorder
    vector<int> result;
    obj.postorder(root, result);

    // Output postorder
    cout << "Postorder Traversal: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
