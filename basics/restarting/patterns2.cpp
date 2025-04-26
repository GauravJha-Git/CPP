//pallindrome pattern

#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for (int row = 1; row <= n; row++) {
        // Print spaces
        for (int space = 1; space <= n - row; space++) {
            cout << " ";
        }

        // Print ascending numbers
        for (int num = 1; num <= row; num++) {
            cout << num;
        }

        // Print descending numbers
        for (int num = row - 1; num >= 1; num--) {
            cout << num;
        }

        cout << endl;
    }

    return 0;
}