#include <bits/stdc++.h>
using namespace std;

// ---------- Tree Node Definition ----------
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ---------- Solution Class with sumK ----------
class Solution {
public:
    // Function to return count of paths with sum k
    int sumK(Node *root, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // Base case: sum 0 occurs once
        return dfs(root, 0, k, prefixSumCount);
    }

private:
    // DFS with prefix sum logic
    int dfs(Node* node, int currSum, int k, unordered_map<int, int>& prefixSumCount) {
        if (!node) return 0;

        currSum += node->data;
        int count = 0;

        // Check if a valid path sum ends here
        if (prefixSumCount.find(currSum - k) != prefixSumCount.end())
            count += prefixSumCount[currSum - k];

        // Mark current sum
        prefixSumCount[currSum]++;

        // Recurse to left and right
        count += dfs(node->left, currSum, k, prefixSumCount);
        count += dfs(node->right, currSum, k, prefixSumCount);

        // Backtrack - remove current sum
        prefixSumCount[currSum]--;

        return count;
    }
};

// ---------- Sample Tree Builder ----------
Node* buildSampleTree() {
    /*
            1
           / \
          2   3
         /   / \
        1   1   -1
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->right->left = new Node(1);
    root->right->right = new Node(-1);
    return root;
}

// ---------- Main Function ----------
int main() {
    Node* root = buildSampleTree();
    int k = 3;

    Solution sol;
    int result = sol.sumK(root, k);
    cout << "Number of paths with sum " << k << ": " << result << endl;

    return 0;
}

/*
🧾 Problem Statement:
Given a binary tree and an integer k, count the number of downward paths where 
the sum of node values is equal to k. A path must go from parent to child.

🧠 Approach:
- Use DFS + Prefix Sum.
- Track current path sum and check if (currSum - k) exists in map.
- Backtrack after visiting children.

⏱️ Time: O(N)
📦 Space: O(N)

Sample Output:
Number of paths with sum 3: 2
*/
