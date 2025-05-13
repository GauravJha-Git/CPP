/* 
-----------------------------------------------
🧾 QUESTION: Print Anagrams Together
-----------------------------------------------
You are given an array of strings. Return all groups of strings that are anagrams.
The strings in each group must appear in the same order as they appear in the original array.

🔢 Input:
arr[] = ["act", "god", "cat", "dog", "tac"]

✅ Output:
[["act", "cat", "tac"], ["god", "dog"]]

📌 Constraints:
1 <= arr.size() <= 100
1 <= arr[i].length() <= 10
-----------------------------------------------

💡 APPROACH:
1. Sort each word → gives a common key for all anagrams.
2. Use an unordered_map where:
   - Key = sorted string
   - Value = list of original words that match this sorted key.
3. Return all groups from the map.

📈 Time Complexity: O(N * K log K)
   - N = number of strings, K = max string length
📦 Space Complexity: O(N * K)
-----------------------------------------------
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// 👇 Main solution class
class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> mp;

        // Group strings by their sorted version
        for (string& word : arr) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            mp[sortedWord].push_back(word);
        }

        // Collect grouped anagrams
        vector<vector<string>> result;
        for (auto& entry : mp) {
            result.push_back(entry.second);
        }

        return result;
    }
};

// 👇 Driver Code - do not modify
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string>> result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}
