#include <iostream>
using namespace std;

int main() {
    int rows = 4, cols = 5;

    for (int row = 1; row <= rows; row++) {
        for (int col = 1; col <= cols; col++) {
            if (row == 1 || row == rows || col == 1 || col == cols) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}
