// C++ program to find the power set using
// binary representation of a number.

#include <bits/stdc++.h>
using namespace std;

vector<string> allPossibleStrings(string &s) {
    int n = s.size();
    vector<string> res;

    // Iterate through all subsets (represented by 0 to 2^n - 1)
    for (int i = 0; i < (1 << n); i++) { 
        string sub = "";
        for (int j = 0; j < n; j++) {
       if (i & (1 << j)) sub += s[j];
        }
        res.push_back(sub);  
    }

      
    return res;
}

int main() {
    string s = "abc";
    vector<string> subsets = allPossibleStrings(s);
     for (string sub : subsets) cout << sub << endl;
    return 0;
}