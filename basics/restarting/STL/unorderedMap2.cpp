//  Bonus Q4: Given a string, print the frequency of each character
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string str = "gauravjha";
    unordered_map<char, int> freq;

    for (char ch : str) {
        freq[ch]++;
    }

    cout << "Character Frequencies:\n";
    for (auto pair : freq) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}
