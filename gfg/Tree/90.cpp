/*
🟩 QUESTION: K-th Smallest Element in BST

Given a Binary Search Tree (BST) and an integer `k`, return the k-th smallest element in the BST. 
If the element doesn't exist (i.e. `k` is larger than the number of nodes), return -1.

Example:
Input: 
          20
         /  \
        8    22
       / \
      4  12
         / \
        10 14
k = 3

Output: 10

Explanation: In-order traversal gives [4, 8, 10, 12, 14, 20, 22]; 3rd element is 10.

Constraints:
1 <= number of nodes <= 10^5
1 <= k <= 10^5
1 <= node->data <= 10^5
*/

/*
🧠 APPROACH:
- Perform an in-order traversal of the BST (left → root → right).
- In-order traversal of a BST gives sorted order.
- Maintain a counter. Increment it each time a node is visited.
- When counter reaches k, record the current node’s value.
- If traversal ends before reaching k, return -1.
*/

/*
✅ TIME COMPLEXITY:
- Time: O(k) average, O(n) worst case
- Space: O(h), where h is the height of the tree
*/

#include <iostream>
using namespace std;

/* 🌳 Definition for a binary tree node */
struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

/* 🔍 Solution class with recursive in-order traversal */
class Solution {
public:
    int count = 0;
    int result = -1;

    void inorder(Node* root, int k) {
        if (!root || result != -1) return;

        inorder(root->left, k);

        count++;
        if (count == k) {
            result = root->data;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(Node* root, int k) {
        count = 0;
        result = -1;
        inorder(root, k);
        return result;
    }
};

/* 🧪 Utility function to build a sample tree */
Node* buildSampleTree() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    return root;
}

/* 🧵 Main function */
int main() {
    Node* root = buildSampleTree();
    int k = 3;

    Solution obj;
    int ans = obj.kthSmallest(root, k);

    if (ans == -1)
        cout << "K-th smallest element does not exist.\n";
    else
        cout << "The " << k << "-th smallest element is: " << ans << endl;

    return 0;
}
