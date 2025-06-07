/**************************************************
    🧾 QUESTION: Remove Loop in Linked List

    Given a singly linked list that might contain a loop.
    Your task is to remove the loop without losing any nodes.
    
    A loop exists if a node’s next pointer points to a previous node in the list.
    
    ➤ Example:
    Input: 1 -> 2 -> 3 -> 4 -> 5 -> (points back to 2)
    Output: 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    ➤ Constraints:
    1 ≤ size of linked list ≤ 10^5
**************************************************/

#include <iostream>
using namespace std;

/**************************************************
    ✅ APPROACH & EXPLANATION

    1. Use Floyd's Cycle Detection Algorithm (slow & fast pointer) to detect the loop.
    2. If a loop is found, find the start of the loop:
       - Reset slow to head
       - Move both slow and fast one step at a time
       - When slow->next == fast->next, break the loop
    3. Remove the loop by setting fast->next = NULL
**************************************************/

// Structure for Linked List Node
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Core logic to remove loop
class Solution {
public:
    void removeLoop(Node* head) {
        if (head == NULL || head->next == NULL) return;

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect loop using Floyd’s Cycle Detection
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;
            }
        }

        // If no loop is found
        if (slow != fast) return;

        // Step 2: Find the start of the loop
        slow = head;

        // Special case: loop starts at head
        if (slow == fast) {
            while (fast->next != slow) {
                fast = fast->next;
            }
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Step 3: Remove the loop
        fast->next = NULL;
    }
};

/**************************************************
    🔄 UTILITY FUNCTIONS
**************************************************/

// Create loop at position 'pos' (1-based index)
void createLoop(Node* head, int pos) {
    if (pos == 0) return;

    Node* loopNode = head;
    for (int i = 1; i < pos; i++) {
        loopNode = loopNode->next;
    }

    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = loopNode;
}

// Detect loop for testing
bool detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

// Print linked list (will hang if loop exists)
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

/**************************************************
    🧪 MAIN FUNCTION TO TEST
**************************************************/

int main() {
    // Creating nodes manually
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int pos = 2; // Creates loop to node with value 2
    createLoop(head, pos);

    Solution sol;

    cout << "Loop detected before removal: " << (detectLoop(head) ? "Yes" : "No") << endl;

    sol.removeLoop(head);

    cout << "Loop detected after removal: " << (detectLoop(head) ? "Yes" : "No") << endl;

    cout << "Linked List after removing loop:\n";
    printList(head);

    return 0;
}
