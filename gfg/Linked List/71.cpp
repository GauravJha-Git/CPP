/*
Detect Loop in Linked List
Difficulty: Medium

Problem:
You are given the head of a singly linked list. Your task is to determine if the linked list contains a loop. 
A loop exists if the next pointer of the last node points to any other node in the list (including itself), rather than being null.

Input:
- head: pointer to the first node of the linked list

Output:
- Return true if there is a loop, otherwise false.

Example:
Input: 1 -> 3 -> 4, last node points to node at position 2 (1-based)
Output: true

Input: 1 -> 8 -> 3 -> 4, last node points to null (pos = 0)
Output: false

Constraints:
- Number of nodes: 1 to 10^4
- Node data: 1 to 10^3
- pos (position of loop connection): 0 to number of nodes
*/

/*
Approach:
We use Floyd’s Cycle Detection Algorithm (Tortoise and Hare):

- Initialize two pointers: slow and fast, both at head.
- Move slow by one step and fast by two steps in each iteration.
- If at any point, slow and fast point to the same node, there is a loop.
- If fast or fast->next becomes NULL, it means no loop is present.

This works because if there is a loop, the faster pointer will eventually lap the slower pointer inside the loop.
*/

/*
Code Implementation:
*/

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
    // Function to detect if a loop exists in the linked list
    bool detectLoop(Node* head) {
        if (head == nullptr) return false;

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // move slow by 1 step
            fast = fast->next->next;    // move fast by 2 steps

            if (slow == fast) {
                // loop detected
                return true;
            }
        }
        // no loop
        return false;
    }
};

/*
Code Explanation:
- Two pointers (slow and fast) start at the head of the list.
- In a loop, slow moves 1 node at a time, fast moves 2 nodes at a time.
- If there is a loop, eventually slow and fast will meet inside the loop.
- If the fast pointer reaches the end of the list (NULL), there is no loop.
- Time complexity: O(N), space complexity: O(1).
*/

/*
Example Usage:
*/

int main() {
    // Create linked list: 1 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);

    // Creating loop: last node points to second node (pos = 2)
    Node* temp = head;
    Node* loopNode = nullptr;
    int pos = 2;  // position where loop connects

    int count = 1;
    while (temp->next != nullptr) {
        if (count == pos) {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }
    // Creating the loop
    temp->next = loopNode;

    Solution sol;
    if (sol.detectLoop(head)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
