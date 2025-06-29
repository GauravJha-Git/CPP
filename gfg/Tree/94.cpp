/*
🎯 Problem: Serialize and Deserialize a Binary Tree

You are given the root of a binary tree. Your task is to:

1. Serialize the tree: Convert the tree into a vector (array) so that it can be stored or transmitted.
2. Deserialize: Reconstruct the tree from the array.

Implement the functions:
    vector<int> serialize(Node* root);
    Node* deSerialize(vector<int>& arr);

Constraints:
- 1 ≤ Number of nodes ≤ 10^4
- 1 ≤ Node value ≤ 10^9 (only positive integers)

Approach:
🔹 Use Level Order Traversal (Breadth First Search).
🔹 For serialization:
    - Traverse tree level by level.
    - Use -1 to indicate NULL nodes since node values are positive.
🔹 For deserialization:
    - Reconstruct the tree using the array and a queue.

*/

// ---------- HEADER FILES ----------
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ---------- NODE STRUCTURE ----------
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ---------- SOLUTION CLASS ----------
class Solution {
  public:
    // Function to serialize the tree
    vector<int> serialize(Node *root) {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr) {
                result.push_back(curr->data);
                q.push(curr->left);
                q.push(curr->right);
            } else {
                result.push_back(-1); // NULL marker
            }
        }
        return result;
    }

    // Function to deserialize and build the tree
    Node* deSerialize(vector<int> &arr) {
        if (arr.empty() || arr[0] == -1) return NULL;

        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < arr.size()) {
            Node* curr = q.front();
            q.pop();

            // Left child
            if (arr[i] != -1) {
                curr->left = new Node(arr[i]);
                q.push(curr->left);
            }
            i++;

            // Right child
            if (i < arr.size() && arr[i] != -1) {
                curr->right = new Node(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};

// ---------- HELPER FUNCTION ----------
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ---------- MAIN FUNCTION ----------
int main() {
    /*
        Sample Tree:
                10
               /  \
             20    30
            /  \
          40    60
    */

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    Solution obj;

    // Serialize the tree
    vector<int> serialized = obj.serialize(root);
    cout << "Serialized Tree: ";
    for (int val : serialized) cout << val << " ";
    cout << endl;

    // Deserialize to rebuild the tree
    Node* newRoot = obj.deSerialize(serialized);

    // Check with inorder traversal
    cout << "Inorder of Deserialized Tree: ";
    inorder(newRoot);  // Expected: 40 20 60 10 30
    cout << endl;

    return 0;
}
