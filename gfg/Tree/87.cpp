/***************************************************************
🧾 Problem: Maximum Path Sum from Any Node in a Binary Tree

Given a binary tree, find the maximum path sum. 
The path can start and end at any node. Each node can be used at most once.

🔹 Constraints:
- 1 ≤ number of nodes ≤ 10^3
- -10^4 ≤ node->data ≤ 10^4

🧪 Example 1:
Input Tree: 
       10
      /  \
     2    10
    / \     \
   20  1    -25
              / \
             3   4

Output: 42
Path: 20 → 2 → 10 → 10

🧪 Example 2:
Input Tree:
       -17
       /  \
     11    4
    /  \     \
   20  -2    10

Output: 31
Path: 20 → 11 → -17 → 4 → 10

***************************************************************/

/***************************************************************
✅ Approach:
1. Use post-order traversal to explore left and right subtrees.
2. At each node:
   - Calculate max path from left and right.
   - Update global max if (left + right + node) is larger.
3. Return the max path using either left or right (not both).

***************************************************************/

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// Tree Node definition
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    // Helper function to calculate max path and update global result
    int helper(Node* root, int &res) {
        if (root == NULL) return 0;

        // Get max path sum from left and right (ignore negatives)
        int left = max(0, helper(root->left, res));
        int right = max(0, helper(root->right, res));

        // Calculate max path including current node as root
        int max_through_root = left + right + root->data;

        // Update global result if this path is better
        res = max(res, max_through_root);

        // Return the best one-side path to parent
        return max(left, right) + root->data;
    }

    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        int res = INT_MIN;  // Initialize result
        helper(root, res);  // Call helper
        return res;         // Return the result
    }
};

// 🔽 Main function to test the logic
int main() {
    /*
        Construct the following tree:
               10
              /  \
             2    10
            / \     \
           20  1    -25
                      / \
                     3   4
        Expected Output: 42
    */

    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    Solution obj;
    cout << "Maximum Path Sum: " << obj.findMaxSum(root) << endl;

    return 0;
}
