/*
🧾 Question:
Left Rotate a Linked List by K nodes

Given the head of a singly linked list and an integer `k`,
rotate the list to the left by `k` nodes.

Examples:

Input:  head = 10 -> 20 -> 30 -> 40 -> 50, k = 4
Output: 50 -> 10 -> 20 -> 30 -> 40

Input:  head = 10 -> 20 -> 30 -> 40, k = 6
Output: 30 -> 40 -> 10 -> 20

Constraints:
- 1 ≤ number of nodes ≤ 10⁵
- 0 ≤ k ≤ 10⁹
- 0 ≤ data of node ≤ 10⁹
*/

/*
🧠 Approach:

1. Handle edge cases (empty list, 1 node, or k == 0).
2. Traverse the list once to find length and last node.
3. Compute k = k % length (effective rotation).
4. Move to the kth node and mark it as the new tail.
5. Make the next node as new head.
6. Link the old tail to the old head.
7. Break the link at the kth node and return the new head.
*/

/* 💻 Code */
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: Count the length and get the last node
        Node* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }

        // Step 2: Effective rotations
        k = k % length;
        if (k == 0) return head;

        // Step 3: Traverse to the kth node
        Node* current = head;
        for (int i = 1; i < k; i++) {
            current = current->next;
        }

        // Step 4: Update pointers
        Node* newHead = current->next;
        current->next = nullptr;
        temp->next = head;

        return newHead;
    }
};

/*
📘 Code Explanation:

- If list is empty or has only one node, we return as-is.
- Count the total nodes to handle cases where k > length.
- Use modulo to avoid extra rotations.
- Move to kth node → split the list.
- Set next node as new head.
- Connect old tail to old head to complete the rotation.
- Break the old link and return the rotated list's new head.
*/

