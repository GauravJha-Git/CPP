// Input: 5

// Output:
// 12345
// 1234
// 123
// 12
// 1
// Inverted Half pyramid
#include <iostream>
using namespace std;

int main() {
    int n = 5;
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}
