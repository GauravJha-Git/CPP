// 1
// 121
// 12321
// 1234321
// 123454321
// Full number pyramid
#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for(int i = 1; i <= n; i++) {
        //Print spaces
        for(int space = 1; space <= n - i; space++) {
            cout << " ";
        }

        // Increasing numbers
        for(int num = 1; num <= i; num++) {
            cout << num;
        }

        // Decreasing numbers
        for(int num = i - 1; num >= 1; num--) {
            cout << num;
        }

        cout << endl;
    }

    return 0;
}
