/*
Problem: Clone Linked List with Next and Random Pointers

You are given a special linked list with n nodes where each node has two pointers:
- 'next' pointer that points to the next node in the list.
- 'random' pointer that points to any random node in the list or NULL.

Your task is to create a **deep copy** of the linked list. The cloned list should have the same structure as the original list,
but none of the pointers in the cloned list should point to nodes in the original list.

Constraints:
- 1 <= n <= 100
- 0 <= node->data <= 1000

Example:
Input: head = [[1, 3], [3, 3], [5, NULL], [9, 3]]
Output: head = [[1, 3], [3, 3], [5, NULL], [9, 3]]

Explanation:
- Node 1's next is Node 2, random is Node 3.
- Node 2's next is Node 3, random is Node 3.
- Node 3's next is Node 4, random is NULL.
- Node 4's next is NULL, random is Node 3.

---

Approach (Optimal O(1) space):

1. For each node in the original list, create a new node and insert it immediately after the original node.
   After this step, the list looks like: 
   original1 -> clone1 -> original2 -> clone2 -> original3 -> clone3 -> ...

2. Set the `random` pointer of each cloned node:
   cloned_node->random = original_node->random->next (because cloned node is right after original node)

3. Separate the original and cloned nodes to form two independent lists:
   - Restore the original list by skipping cloned nodes.
   - Extract the cloned list by skipping original nodes.

Time Complexity: O(n)
Space Complexity: O(1)

---

Code Implementation:
*/

#include <iostream>
using namespace std;

// Definition for the Node of the linked list
struct Node {
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* cloneLinkedList(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;

        // Step 1: Insert cloned nodes after original nodes
        while (curr) {
            Node* newNode = new Node(curr->data);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: Set random pointers of cloned nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the original and cloned lists
        curr = head;
        Node* cloneHead = head->next;
        Node* cloneCurr = cloneHead;

        while (curr) {
            curr->next = curr->next->next;
            if (cloneCurr->next)
                cloneCurr->next = cloneCurr->next->next;

            curr = curr->next;
            cloneCurr = cloneCurr->next;
        }

        return cloneHead;
    }
};

// Helper function to print list along with random pointers
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << "Node data: " << curr->data << ", Random data: ";
        if (curr->random) cout << curr->random->data;
        else cout << "NULL";
        cout << endl;
        curr = curr->next;
    }
}

// Example usage
int main() {
    // Creating original list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Setting random pointers
    head->random = head->next->next;       // 1's random -> 3
    head->next->random = head;             // 2's random -> 1
    head->next->next->random = head->next; // 3's random -> 2

    cout << "Original list:" << endl;
    printList(head);

    Solution sol;
    Node* clonedHead = sol.cloneLinkedList(head);

    cout << "\nCloned list:" << endl;
    printList(clonedHead);

    return 0;
}
// Explanation:
// Step 1: For each node, we create a copy and insert it immediately after the original node.

// Step 2: Since the copied node is right after the original, the random pointer of the copied node is simply the next node of the original node’s random.

// Step 3: Finally, restore the original list and separate the copied nodes to form the cloned list.

// This method achieves deep copy without extra space for hashing and runs in linear time.