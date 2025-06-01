/*
🧾 Question: Merge Two Sorted Linked Lists

You are given the heads of two sorted linked lists.
Your task is to merge them into a single sorted linked list
and return the head of the new merged list.

✨ Constraints:
- 1 ≤ Number of nodes ≤ 1000
- 0 ≤ Node data ≤ 10^5
- Both linked lists are sorted in ascending order.

🔹 Example 1:
Input:  
head1 = 5 -> 10 -> 15 -> 40  
head2 = 2 -> 3 -> 20  

Output:  
2 -> 3 -> 5 -> 10 -> 15 -> 20 -> 40

🔹 Example 2:
Input:  
head1 = 1 -> 1  
head2 = 2 -> 4  

Output:  
1 -> 1 -> 2 -> 4
*/

/*
🧠 Approach: Iterative Merge using a Dummy Node

🔍 Explanation:
- Use a dummy node to simplify merging logic.
- Keep a `tail` pointer to track the last node of the merged list.
- Compare current nodes of both lists.
- Attach the smaller node to the merged list.
- Move the pointer (head1 or head2) forward.
- After the loop, attach the remaining nodes of the non-empty list.
*/

// Definition for singly-linked list node
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
    Node* sortedMerge(Node* head1, Node* head2) {
        Node dummy(0);  // Dummy node to simplify merging
        Node* tail = &dummy;

        // Merge nodes in sorted order
        while (head1 != NULL && head2 != NULL) {
            if (head1->data < head2->data) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }

        // Attach the remaining nodes
        if (head1 != NULL) {
            tail->next = head1;
        } else {
            tail->next = head2;
        }

        return dummy.next;  // Head of merged list
    }
};

/*
📘 Code Explanation:
- dummy: Temporary start node to avoid handling special cases for head.
- tail: Keeps track of the last node in the merged list.
- Inside the loop, the smaller of head1 and head2 is added to the merged list.
- When one list is finished, the rest of the other list is added directly.
*/

