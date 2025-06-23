/*
✅ Question: Check for BST

Difficulty: Easy
Accuracy: 25.37%
Average Time: 30 minutes

Given the root of a binary tree, check whether it is a Binary Search Tree (BST) or not.

A BST is defined as follows:
1. The left subtree of a node contains only nodes with keys less than the node’s key.
2. The right subtree of a node contains only nodes with keys greater than the node’s key.
3. Both the left and right subtrees must also be binary search trees.

Note: BSTs cannot contain duplicate nodes.

Example 1:
Input: root = [2, 1, 3, N, N, N, 5]
Output: true
Explanation: All left nodes are smaller and all right nodes are greater.

Example 2:
Input: root = [10, 5, 20, N, N, 9, 25]
Output: false
Explanation: Node with value 9 is in the right subtree of 10 but is less than 10 — violates BST rule.

Constraints:
1 ≤ number of nodes ≤ 10^5
1 ≤ node->data ≤ 10^9
*/

/*
✅ Approach: Using Min-Max Range Recursion

We check for each node:
- It must lie within a valid min and max range.
- For left child: new max = node->data
- For right child: new min = node->data
*/

/*
✅ Explanation:
The idea is to ensure:
- Left child < current node
- Right child > current node
- Recursively check this rule for every subtree

We start with the range (-∞, ∞) for the root, and update the range as we move down.
*/

#include <iostream>
#include <climits>  // For LLONG_MIN and LLONG_MAX
using namespace std;

// Definition for binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    // Helper function to check BST validity within range
    bool isBSTUtil(Node* node, long long minVal, long long maxVal) {
        if (!node) return true;  // Empty tree is BST

        // Current node violates BST property
        if (node->data <= minVal || node->data >= maxVal)
            return false;

        // Recur for left and right subtrees with updated ranges
        return isBSTUtil(node->left, minVal, node->data) &&
               isBSTUtil(node->right, node->data, maxVal); 
    }

    // Main function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }
};

/*
✅ Code Explanation:
- isBSTUtil is a recursive function that checks the BST rule.
- It returns true if:
  - the current node’s value lies in (minVal, maxVal)
  - and its left and right subtrees also follow BST rules
- LLONG_MIN and LLONG_MAX are used to ensure no limits initially.
*/

// 🔹 Main function to test the BST checker
int main() {
    /*
        Example Tree:
               10
              /  \
             5    20
                 /  \
                9   25

        This is NOT a BST because 9 is in the right subtree of 10 but less than 10
    */
    
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(9);
    root->right->right = new Node(25);

    Solution sol;
    if (sol.isBST(root)) {
        cout << "The tree is a BST" << endl;
    } else {
        cout << "The tree is NOT a BST" << endl;
    }

    return 0;
}
