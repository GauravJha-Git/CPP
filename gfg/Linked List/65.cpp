/*
Reverse a Linked List

Question:
Given the head of a singly linked list, reverse the list and return the new head of the reversed list.

Example:
Input: 1 -> 2 -> 3 -> 4 -> NULL
Output: 4 -> 3 -> 2 -> 1 -> NULL

Constraints:
- Number of nodes: 1 to 10^5
- Node values can be any integer

Approach:
1. Use three pointers: prev (initially nullptr), curr (head), next_node (temporary).
2. Iterate through the list:
   - Store curr->next in next_node.
   - Point curr->next to prev to reverse the link.
   - Move prev to curr.
   - Move curr to next_node.
3. When curr is nullptr, prev points to the new head.
4. Return prev.
*/

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to print linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL\n";
}

// Solution class with reverse function
class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next_node = nullptr;
        
        while (curr != nullptr) {
            next_node = curr->next;  // Save next node
            curr->next = prev;       // Reverse pointer
            prev = curr;             // Move prev forward
            curr = next_node;        // Move curr forward
        }
        
        return prev;  // New head of reversed list
    }
};

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    
    cout << "Original List:\n";
    printList(head);
    
    Solution sol;
    Node* reversedHead = sol.reverseList(head);
    
    cout << "Reversed List:\n";
    printList(reversedHead);
    
    return 0;
}
