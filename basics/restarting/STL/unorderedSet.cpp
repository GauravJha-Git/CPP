#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> rollNumbers;
    int rolls[] = {101, 102, 103, 102, 104, 101};

    for (int i = 0; i < 6; i++) {
        rollNumbers.insert(rolls[i]);
    }

    cout << "Unique roll numbers: ";
    for (int roll : rollNumbers) {
        cout << roll << " ";
    }
    return 0;
}
