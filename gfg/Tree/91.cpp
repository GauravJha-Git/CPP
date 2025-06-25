// ✅ Problem Statement:
// Given the root of a Binary Search Tree (BST) and an integer target,
// check if there exist two nodes in the BST such that their values add up to the target.

// 💡 Approach:
// 1. Perform inorder traversal of BST to get a sorted array of node values.
// 2. Use two-pointer technique on the sorted array to check if any two numbers sum to the target.
// Time: O(N), Space: O(N)

#include <iostream>
#include <vector>
using namespace std;

// ✅ Node structure
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ✅ Solution class
class Solution {
public:
    // Inorder traversal to get sorted array
    void inorder(Node* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    // Function to find if there is a pair with given target sum
    bool findTarget(Node* root, int target) {
        vector<int> sorted;
        inorder(root, sorted);  // Step 1: BST to sorted array

        int left = 0, right = sorted.size() - 1;

        // Step 2: Two-pointer approach
        while (left < right) {
            int sum = sorted[left] + sorted[right];
            if (sum == target)
                return true;
            else if (sum < target)
                left++;
            else
                right--;
        }

        return false; // No pair found
    }
};

// ✅ Main function for testing
int main() {
    /*
           7
         /   \
        3     8
       / \     \
      2   4     9
    */

    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(9);

    int target = 12;

    Solution sol;
    bool result = sol.findTarget(root, target);

    if (result)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}

/*
📘 Code Explanation:
- Node: defines the structure of each BST node.
- inorder(): traverses BST in-order and stores values in a sorted array.
- findTarget(): uses two-pointer technique to find if any two values sum to the target.
- main(): builds the sample BST, sets the target, and prints result.
*/
