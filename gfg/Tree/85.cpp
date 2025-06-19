/*
💡 QUESTION: Inorder Traversal

You're given the root of a binary tree.
Return the inorder traversal of its nodes' values.

🔁 Inorder Traversal Order:
Left → Root → Right

--------------------------------------------

📥 EXAMPLES:

Example 1:
Input Tree:
        1
       / \
      2   3
     / \
    4   5

Output:
[4, 2, 5, 1, 3]

--------------------------------------------

Example 2:
Input Tree:
        8
       / \
      1   5
       \  / \
        7 10 6
           /
         10
         /
        6

Output:
[1, 7, 10, 8, 6, 10, 5, 6]

--------------------------------------------

📌 CONSTRAINTS:
- 1 <= Number of nodes <= 10^5
- 0 <= Node->data <= 10^5

--------------------------------------------

✅ APPROACH: Recursive Inorder Traversal

We recursively visit:
1. Left Subtree
2. Current Node
3. Right Subtree

We store each node's data in a result vector.

--------------------------------------------

✍️ CODE:
*/

// Tree Node definition
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Solution class
class Solution {
  public:
    // Helper function for recursive inorder traversal
    void inorderHelper(Node* root, vector<int>& result) {
        if (root == NULL) return;

        inorderHelper(root->left, result);      // Visit left child
        result.push_back(root->data);           // Visit current node
        inorderHelper(root->right, result);     // Visit right child
    }

    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
};

/*
--------------------------------------------

🧠 CODE EXPLANATION:

- inOrder():
  - Called with root node.
  - Creates a vector to store result.
  - Calls helper function to fill the result.

- inorderHelper():
  - Recursively goes to left subtree.
  - Adds current node's data to result.
  - Recursively goes to right subtree.

➡️ Ensures order: Left → Root → Right

--------------------------------------------

⚡ FOLLOW-UP:

To reduce space usage to O(1), you can use Morris Traversal.
Ask if you want that version too.

*/
