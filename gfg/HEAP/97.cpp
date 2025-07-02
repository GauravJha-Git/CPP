/*
Problem: Merge K Sorted Linked Lists

You are given an array of `k` sorted linked lists. Your task is to merge all these lists into one single sorted linked list and return the head of the merged list.

Example:
Input:
arr[] = [1 -> 2 -> 3, 4 -> 5, 5 -> 6, 7 -> 8]

Output:
1 -> 2 -> 3 -> 4 -> 5 -> 5 -> 6 -> 7 -> 8

Approach:
- Use a min heap (priority queue) to store the head nodes of each list.
- Always extract the node with the smallest value and push its next node to the heap.
- Repeat until the heap is empty.

Time Complexity: O(N log K)
Where N = total number of nodes, K = number of linked lists.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Structure of a linked list node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Custom comparator for min heap
struct compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, compare> pq;

        // Push the head of each list into the priority queue
        for (auto list : arr) {
            if (list != NULL) {
                pq.push(list);
            }
        }

        Node* dummy = new Node(0);  // Dummy node for result list
        Node* tail = dummy;

        // Build merged linked list
        while (!pq.empty()) {
            Node* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = tail->next;

            if (curr->next != NULL) {
                pq.push(curr->next);
            }
        }

        return dummy->next;
    }
};

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Function to create a linked list from a vector of integers
Node* createList(vector<int> vals) {
    if (vals.empty()) return NULL;
    Node* head = new Node(vals[0]);
    Node* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new Node(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Main function
int main() {
    // Create K sorted linked lists
    vector<Node*> lists;
    lists.push_back(createList({1, 2, 3}));
    lists.push_back(createList({4, 5}));
    lists.push_back(createList({5, 6}));
    lists.push_back(createList({7, 8}));

    Solution sol;
    Node* mergedHead = sol.mergeKLists(lists);

    cout << "Merged Linked List:\n";
    printList(mergedHead);

    return 0;
}
