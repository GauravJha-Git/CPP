/*
📄 QUESTION:
Given the root of a binary tree, find its height.
- Height = Number of edges on the longest path from root to a leaf node.
- A leaf node is a node with no children.

🧪 EXAMPLES:

Example 1:
Input: [12, 8, 18, 5, 11]
Tree:
        12
       /  \
      8    18
     / \
    5  11
Output: 2

Example 2:
Input: [1, 2, 3, 4, N, N, 5, N, N, 6, 7]
Tree:
        1
       / \
      2   3
     /     \
    4       5
           /
          6
         /
        7
Output: 3

✅ Constraints:
- 1 <= number of nodes <= 10^5
- 0 <= node->data <= 10

💡 APPROACH:
We use recursion (depth-first traversal):
1. If node is NULL → return -1 (because height = number of edges).
2. Recursively find height of left and right subtrees.
3. Return 1 + max(left, right)

🧠 EXPLANATION:
- Height counts edges.
- Leaf node = height 0
- NULL = base case, height = -1
- Add +1 for each level going up

🧾 COMPLETE CODE:
*/

#include <iostream>
#include <algorithm>
using namespace std;

/* Binary Tree Node definition */
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

/* Solution class */
class Solution {
public:
    int height(Node* node) {
        if (node == NULL) {
            return -1;  // base case: no edge
        }

        int leftHeight = height(node->left);     // height of left subtree
        int rightHeight = height(node->right);   // height of right subtree

        return 1 + max(leftHeight, rightHeight); // count edge to deeper side
    }
};

/* Main to test the code */
int main() {
    // Sample tree:
    //         12
    //        /  \
    //       8    18
    //      / \
    //     5  11

    Node* root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);

    Solution sol;
    cout << "Height of tree: " << sol.height(root) << endl;  // Expected output: 2

    return 0;
}

/*
🧾 CODE EXPLANATION:

- height(node):
    - Returns -1 if node is NULL (edge count logic).
    - Recursively calculates left and right subtree heights.
    - Returns 1 + max(left, right) for current node’s height.

- main():
    - Builds a binary tree.
    - Calls height() function.
    - Prints the result.
*/
