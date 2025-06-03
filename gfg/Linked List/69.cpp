/*
--------------------------------------------
🧠 Problem: Add Number Linked Lists
--------------------------------------------

You are given the heads of two singly linked lists num1 and num2, representing two non-negative integers. 
The digits are stored in FORWARD ORDER (most significant digit first).

You need to return the head of a linked list representing the sum of these two numbers, also in forward order.

⚠️ Note: Input lists can have leading zeros. Output list must not have leading zeros.

--------------------------------------------
📌 Examples:

Input:  num1 = 1 -> 9 -> 0
        num2 = 2 -> 5
Output: 2 -> 1 -> 5

Explanation:
Number 1 = 190
Number 2 = 25
Sum = 215 => 2 -> 1 -> 5


Input:  num1 = 0 -> 0 -> 6 -> 3
        num2 = 0 -> 7
Output: 7 -> 0

Explanation:
Number 1 = 63
Number 2 = 7
Sum = 70 => 7 -> 0

--------------------------------------------
💡 Approach:

1. Reverse both input linked lists to start addition from the least significant digit.
2. Add corresponding digits with carry.
3. If carry remains after list ends, add it too.
4. Reverse the result to restore original order.
5. Remove any leading zeros (except when the result is just 0).

--------------------------------------------
✅ Time Complexity: O(N + M)
✅ Space Complexity: O(N + M) for result list
*/

#include <iostream>
using namespace std;

// ---------------------
// Node structure
// ---------------------
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// ---------------------
// Solution Class
// ---------------------
class Solution {
public:
    // Function to reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Main function to add two numbers represented by linked lists
    Node* addTwoLists(Node* num1, Node* num2) {
        num1 = reverse(num1);
        num2 = reverse(num2);
        
        Node* dummy = new Node(0);
        Node* temp = dummy;
        int carry = 0;

        while (num1 != NULL || num2 != NULL || carry != 0) {
            int val1 = (num1 != NULL) ? num1->data : 0;
            int val2 = (num2 != NULL) ? num2->data : 0;
            int sum = val1 + val2 + carry;

            carry = sum / 10;
            temp->next = new Node(sum % 10);
            temp = temp->next;

            if (num1) num1 = num1->next;
            if (num2) num2 = num2->next;
        }

        Node* result = reverse(dummy->next);

        // Remove leading zeros if any
        while (result && result->data == 0 && result->next != NULL) {
            Node* toDelete = result;
            result = result->next;
            delete toDelete;
        }

        return result;
    }
};

// ---------------------
// Utility functions for testing
// ---------------------
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

Node* createList(const initializer_list<int>& values) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int val : values) {
        Node* newNode = new Node(val);
        if (!head)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// ---------------------
// Main function (for testing)
// ---------------------
int main() {
    // Example 1
    Node* num1 = createList({1, 9, 0});
    Node* num2 = createList({2, 5});
    
    Solution sol;
    Node* result = sol.addTwoLists(num1, num2);

    cout << "Output: ";
    printList(result);  // Expected: 2 -> 1 -> 5

    // Example 2
    num1 = createList({0, 0, 6, 3});
    num2 = createList({0, 7});
    result = sol.addTwoLists(num1, num2);

    cout << "Output: ";
    printList(result);  // Expected: 7 -> 0

    return 0;
}
