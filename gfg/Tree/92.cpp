/*
📌 Problem: Fixing Two Nodes of a BST

You are given the root of a Binary Search Tree (BST) in which two nodes are swapped by mistake.
Your task is to fix the BST by swapping them back without changing the structure of the tree.

🧠 Approach:
- Perform in-order traversal which should yield sorted values in a BST.
- Detect the two nodes where the order is violated.
- Track the first, middle, and last nodes:
    - If two violations found: swap first and last.
    - If one violation: swap first and middle.

Time Complexity: O(n)
Space Complexity: O(h) (due to recursion stack)
*/

#include <iostream>
using namespace std;

// 🌳 BST Node structure
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

// 🛠️ Solution class to fix the BST
class Solution {
private:
    Node *first = NULL, *middle = NULL, *last = NULL, *prev = NULL;

    // 🔁 In-order traversal to detect swapped nodes
    void inorder(Node* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && root->data < prev->data) {
            if (!first) {
                // First violation
                first = prev;
                middle = root;
            } else {
                // Second violation
                last = root;
            }
        }
        prev = root;

        inorder(root->right);
    }

public:
    void correctBST(Node* root) {
        first = middle = last = prev = NULL;

        inorder(root);

        // 🧩 Swap detected nodes
        if (first && last) {
            swap(first->data, last->data);
        } else if (first && middle) {
            swap(first->data, middle->data);
        }
    }
};

// 🖨️ Utility: Inorder traversal for checking correctness
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// 🧪 Main function to test the fix
int main() {
    /*
         10
        /  \
       5    8   ← swapped (should be 20)
      / \
     2  20   ← swapped (should be 8)
    */

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(8);  // Swapped
    root->left->left = new Node(2);
    root->left->right = new Node(20); // Swapped

    cout << "Inorder before fixing: ";
    printInorder(root);
    cout << endl;

    Solution obj;
    obj.correctBST(root);

    cout << "Inorder after fixing: ";
    printInorder(root);
    cout << endl;

    return 0;
}
