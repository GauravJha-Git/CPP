/*
🟩 Problem: Diameter of a Binary Tree

Given a binary tree, find the diameter — the number of edges on the longest path 
between any two leaf nodes in the tree. This path may or may not pass through the root.

🔹 Examples:

Input: root[] = [1, 2, 3]
Output: 2
Explanation: Path = 2 -> 1 -> 3 (2 edges)

Input: root[] = [5, 8, 6, 3, 7, 9]
Output: 4
Explanation: Path = 3 -> 8 -> 5 -> 6 -> 9 (4 edges)

🔹 Constraints:
1 ≤ Number of nodes ≤ 10⁵  
0 ≤ Node value ≤ 10⁵
*/

/*
🧠 Approach:

1. Use DFS (postorder traversal) to calculate the height of each subtree.
2. At each node, calculate:
   Diameter through that node = leftHeight + rightHeight
3. Track the maximum diameter encountered.
4. Return that maximum after traversal.
*/

/*
🔍 Explanation:

- We compute the height of left and right subtrees for each node.
- The diameter at a node is the number of edges connecting the deepest node in the left
  to the deepest node in the right subtree.
- While calculating height, we update the global diameter.
*/

#include <bits/stdc++.h>
using namespace std;

// Definition of a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Utility function to create a new node
Node* newNode(int val) {
    return new Node(val);
}

// Solution class containing the logic to compute diameter
class Solution {
public:
    int maxDiameter = 0;

    // Helper function to compute height and update diameter
    int height(Node* node) {
        if (node == NULL) return 0;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Update the diameter at this node
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Return the height of the current node
        return 1 + max(leftHeight, rightHeight);
    }

    // Main function to calculate diameter
    int diameter(Node* root) {
        height(root);
        return maxDiameter;
    }
};

// Sample usage
int main() {
    /*
        Sample Tree:

              5
             / \
            8   6
           / \   \
          3   7   9

        Longest path: 3 -> 8 -> 5 -> 6 -> 9
        Diameter: 4
    */

    Node* root = newNode(5);
    root->left = newNode(8);
    root->right = newNode(6);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->right = newNode(9);

    Solution obj;
    cout << "Diameter of the tree: " << obj.diameter(root) << endl;

    return 0;
}
