/*
----------------------------------------------
💡 Question: LRU Cache (Least Recently Used)
----------------------------------------------

Design and implement a data structure for Least Recently Used (LRU) Cache.

Implement the LRUCache class:

- LRUCache(int capacity): Initializes the LRU cache with positive size capacity.
- int get(int key): Returns the value of the key if it exists in the cache, otherwise returns -1.
- void put(int key, int value): Update the value of the key if it exists. 
  Otherwise, add the key-value pair to the cache. 
  If the number of keys exceeds the capacity, evict the least recently used key.

🔒 Constraints:
- 1 <= capacity <= 1000
- 1 <= Q <= 100000
- 1 <= key, value <= 10000
*/

/*
----------------------------------------------
🧠 Approach:
----------------------------------------------
1. Use a Hash Map for O(1) access to nodes using keys.
2. Use a Doubly Linked List to maintain the usage order:
   - Most recently used → end
   - Least recently used → front
3. On get(key):
   - If found, move node to back and return value.
   - Else, return -1.
4. On put(key, value):
   - If exists, update and move to back.
   - If not, insert at back.
     - If full, remove LRU (front node).
*/

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    // Add a node to the end (most recent)
    void addNode(Node* node) {
        Node* temp = tail->prev;
        temp->next = node;
        node->prev = temp;
        node->next = tail;
        tail->prev = node;
    }

    // Remove a node from the list
    void removeNode(Node* node) {
        Node* before = node->prev;
        Node* after = node->next;
        before->next = after;
        after->prev = before;
    }

public:
    // Constructor
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(0, 0); // dummy head
        tail = new Node(0, 0); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    // Get the value if key exists
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            int val = node->value;
            removeNode(node);
            addNode(node);
            return val;
        }
        return -1;
    }

    // Put key-value pair
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            addNode(node);
        } else {
            if (cache.size() == capacity) {
                Node* lru = head->next; // Least Recently Used
                cache.erase(lru->key);
                removeNode(lru);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);
        }
    }
};

/*
----------------------------------------------
🔁 Example Usage:
----------------------------------------------
*/

int main() {
    LRUCache cache(2); // capacity = 2

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // returns 1
    cache.put(3, 3);              // evicts key 2
    cout << cache.get(2) << endl; // returns -1
    cache.put(4, 4);              // evicts key 1
    cout << cache.get(1) << endl; // returns -1
    cout << cache.get(3) << endl; // returns 3
    cout << cache.get(4) << endl; // returns 4

    return 0;
}
