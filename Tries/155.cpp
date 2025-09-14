#include <bits/stdc++.h>
using namespace std;

//
// 📌 Problem Statement
//
// Implement a Trie (Prefix Tree) with the following operations:
// 1. insert(word)   → Insert a word into the Trie.
// 2. search(word)   → Return true if the word exists in the Trie.
// 3. isPrefix(word) → Return true if the given word is a prefix of any word in the Trie.
//
// You will be given queries in the form:
// [1, word] → insert(word)
// [2, word] → search(word)
// [3, word] → isPrefix(word)
//
// Return the results of type 2 and 3 queries as a boolean list.
//
// Example:
// Input:  [[1, "abcd"], [1, "abc"], [1, "bcd"], [2, "bc"], [3, "bc"], [2, "abc"]]
// Output: false true true
//

//
// 📌 Approach
//
// - Each TrieNode has 26 children (for 'a'–'z') and a boolean flag isEnd.
// - Insert: For each character, create node if missing, move to next.
// - Search: Traverse, if child missing → return false, else check isEnd.
// - isPrefix: Traverse, if traversal succeeds return true (even if isEnd is false).
//

// ---------------- TrieNode definition ----------------
class TrieNode {
  public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

// ---------------- Trie class ----------------
class Trie {
  public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert a word into Trie
    void insert(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    // Search full word in Trie
    bool search(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    // Check if prefix exists in Trie
    bool isPrefix(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return true;
    }
};

// ---------------- Driver function ----------------
int main() {
    // Example queries
    vector<vector<string>> queries = {
        {"1", "abcd"}, {"1", "abc"}, {"1", "bcd"},
        {"2", "bc"}, {"3", "bc"}, {"2", "abc"}
    };

    Trie trie;
    vector<bool> results;

    // Process queries
    for (auto &q : queries) {
        int type = stoi(q[0]);
        string word = q[1];

        if (type == 1) {
            trie.insert(word);
        } else if (type == 2) {
            results.push_back(trie.search(word));
        } else if (type == 3) {
            results.push_back(trie.isPrefix(word));
        }
    }

    // Print results
    for (bool r : results) {
        cout << (r ? "true " : "false ");
    }
    cout << endl;

    return 0;
}

//
// 📌 Code Explanation
//
// - TrieNode: represents each node with 26 children + isEnd flag.
// - Trie: manages root node and has insert, search, isPrefix methods.
// - main(): runs queries, inserts words, searches, and checks prefixes.
//
// Example Run:
// Input:  [[1,"abcd"], [1,"abc"], [1,"bcd"], [2,"bc"], [3,"bc"], [2,"abc"]]
// Output: false true true
//
// Time Complexity:
// - Insert: O(L)   (L = length of word)
// - Search: O(L)
// - isPrefix: O(L)
//
// Space Complexity: O(N * L)  (N = number of words, L = avg length)
//
