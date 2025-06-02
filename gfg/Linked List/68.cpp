/*
📝 Problem: Linked List Group Reverse

Given the head of a singly linked list, reverse every `k` nodes of the list.
If the number of nodes is not a multiple of `k`, reverse the remaining nodes as a group too.

🔹 Examples:

Input:  head = 1 -> 2 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8, k = 4
Output: 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5

Input:  head = 1 -> 2 -> 3 -> 4 -> 5, k = 3
Output: 3 -> 2 -> 1 -> 5 -> 4

🔍 Approach:

1. Count if at least `k` nodes are available.
2. If yes, reverse those `k` nodes using 3-pointer method (curr, prev, next).
3. Recur for the rest of the list.
4. If less than `k` nodes are left at the end, reverse them too.

Time Complexity: O(N)
Space Complexity: O(N/k) due to recursion
*/

#include <iostream>
using namespace std;

// Definition of Node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Solution class with reverseKGroup method
class Solution {
  public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k == 1) return head;

        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        // Step 1: Check if we have at least k nodes
        int count = 0;
        Node* temp = head;
        while (temp != nullptr && count < k) {
            temp = temp->next;
            count++;
        }

        // Step 2: Reverse if count >= k
        if (count >= k) {
            count = 0;
            curr = head;

            // Reverse k nodes
            while (curr != nullptr && count < k) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }

            // Step 3: Recur for remaining list
            if (next != nullptr) {
                head->next = reverseKGroup(next, k);
            }

            // Return new head
            return prev;
        }

        // Step 4: If less than k nodes, reverse them too
        return reverseRemaining(head);
    }

  private:
    // Helper to reverse all remaining nodes
    Node* reverseRemaining(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

// Helper to insert node at end
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Helper to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test
int main() {
    Node* head = nullptr;
    int arr[] = {1, 2, 2, 4, 5, 6, 7, 8};
    int k = 4;

    for (int val : arr) {
        insertAtEnd(head, val);
    }

    cout << "Original List:\n";
    printList(head);

    Solution sol;
    Node* newHead = sol.reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ":\n";
    printList(newHead);

    return 0;
}
