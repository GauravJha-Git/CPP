#include <iostream>
using namespace std;

/* 
==============================
🟩 QUESTION:
==============================

Given a head of the singly linked list. If a loop is present in the list 
then return the first node of the loop else return -1.

Custom Input format:
A head of a singly linked list and a pos (1-based index) which denotes 
the position of the node to which the last node points to. 
If pos = 0, it means the last node points to null (no loop).

Examples:

Input: Linked list with loop starting at node with value 3
Output: 3

Input: Linked list with no loop
Output: -1

Constraints:
1 <= no. of nodes <= 10^6
1 <= node->data <= 10^6

==============================
🟨 APPROACH:
==============================

Use Floyd’s Cycle Detection Algorithm (Tortoise & Hare):

1. Use two pointers `slow` and `fast` to detect the presence of a loop.
2. If they meet, reset `slow` to head and move both one step at a time.
3. The node where they meet again is the start of the loop.
4. If no loop, return -1.

==============================
🟦 EXPLANATION:
==============================

- `slow` moves one step at a time, `fast` moves two.
- If they ever meet, a loop exists.
- To find the start of the loop:
    - Move one pointer to head and keep the other at meeting point.
    - Move both one step at a time.
    - The point where they meet is the starting node of the loop.
- If `fast` becomes NULL, there is no loop.
*/

// Linked list node structure
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Solution class with logic to detect first node of loop
class Solution {
  public:
    Node* findFirstNode(Node* head) {
        if (!head || !head->next)
            return nullptr;

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect Loop
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // Loop detected
            if (slow == fast) {
                // Step 2: Find starting node of loop
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // First node of loop
            }
        }

        // No loop found
        return nullptr;
    }
};

// Utility to insert a loop for testing
void createLoop(Node* head, int pos) {
    if (pos == 0) return;
    Node* loopNode = head;
    for (int i = 1; i < pos; i++) {
        loopNode = loopNode->next;
    }

    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = loopNode;
}

// Driver Code
int main() {
    int n, pos;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n == 0) {
        cout << -1 << endl;
        return 0;
    }

    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter linked list values: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (!head)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Enter position to create loop (0 for no loop): ";
    cin >> pos;

    createLoop(head, pos);

    Solution sol;
    Node* loopStart = sol.findFirstNode(head);

    if (loopStart)
        cout << "First node of loop is: " << loopStart->data << endl;
    else
        cout << -1 << endl;

    return 0;
}

/* 
==============================
🟦 CODE EXPLANATION:
==============================

1. Node structure is defined with constructor.
2. `findFirstNode` uses Floyd’s Cycle Detection:
    - slow = 1 step, fast = 2 steps.
    - If slow == fast, reset slow to head.
    - Move both 1 step → point where they meet is start of loop.
3. `createLoop` makes the last node point to the node at position `pos`.
4. Main() takes input, builds linked list, creates loop, and prints result.

Sample Input:
--------------
Enter number of nodes: 6
Enter linked list values: 1 2 3 4 5 6
Enter position to create loop (0 for no loop): 3

Output:
--------------
First node of loop is: 3
*/
