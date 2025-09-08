/*
 🛸 Alien Dictionary

❓ Question:
A new alien language uses the English alphabet, but the order of letters is unknown. 
You are given a list of words[] sorted lexicographically according to the rules of the alien language.  

Your task is to determine the correct order of letters in this alien language.  
- If a valid order exists, return a string containing the unique letters in that order.  
- If multiple valid orders exist, return any one of them.  
- If no valid order is possible, return an empty string ("").  

Constraints:
1 ≤ words.length ≤ 500
1 ≤ words[i].length ≤ 100
words[i] consists only of lowercase English letters.

---

📖 Example:
Input:  words = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation:
- "baa" < "abcd" → 'b' comes before 'a'
- "abcd" < "abca" → 'd' comes before 'a'
- "abca" < "cab" → 'a' comes before 'c'
- "cab" < "cad" → 'b' comes before 'd'

Valid ordering: "bdac"

---

⚡ Approach:
1. Extract ordering rules from adjacent words.
2. Build graph (directed edges show letter order).
3. Handle invalid case (prefix problem).
4. Perform topological sort (Kahn’s algorithm).
5. If cycle detected → return "".

---

🛠 Algorithm:
1. Initialize indegree map for all characters.
2. Compare words and build graph edges.
3. Use a queue to perform BFS (Kahn’s algorithm).
4. Append characters to result in topological order.
5. If result length < unique characters → cycle → return "".

---

💻 Code:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        // Step 1: Initialize indegree for all unique characters
        for (auto &word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }

        // Step 2: Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min(w1.size(), w2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    if (adj[w1[j]].find(w2[j]) == adj[w1[j]].end()) {
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    found = true;
                    break;
                }
            }

            // Invalid case: word2 is prefix of word1
            if (!found && w1.size() > w2.size()) return "";
        }

        // Step 3: Topological sort using BFS
        queue<char> q;
        for (auto &p : indegree) {
            if (p.second == 0) q.push(p.first);
        }

        string result;
        while (!q.empty()) {
            char c = q.front(); q.pop();
            result += c;

            for (char neigh : adj[c]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) q.push(neigh);
            }
        }

        // Step 4: Cycle check
        if (result.size() != indegree.size()) return "";

        return result;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    Solution obj;

    vector<string> words1 = {"baa", "abcd", "abca", "cab", "cad"};
    cout << (obj.findOrder(words1) != "" ? "true" : "false") << endl;

    vector<string> words2 = {"caa", "aaa", "aab"};
    cout << (obj.findOrder(words2) != "" ? "true" : "false") << endl;

    vector<string> words3 = {"ab", "cd", "ef", "ad"};
    cout << (obj.findOrder(words3) != "" ? "true" : "false") << endl;

    return 0;
}

/*
📝 Code Explanation:
- indegree map: tracks how many characters must come before each letter.
- Build graph: compare adjacent words, first differing char gives edge u→v.
- Prefix check: if word1 is longer and starts with word2 → invalid.
- Topological sort: 
  - Start with letters having indegree 0.
  - Pop from queue, add to result, reduce neighbors’ indegree.
  - Push new indegree-0 nodes into queue.
- If result size != unique characters → cycle → return "".
*/
