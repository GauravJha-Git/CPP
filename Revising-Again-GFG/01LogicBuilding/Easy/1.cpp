#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    int sum = 0;
    while (n != 0) {

        // Extract the last digit
        int last = n % 10;

        // Add last digit to sum
        sum += last;

        // Remove the last digit
        n /= 10;
    }
    return sum;
}

int main() {
    int n = 12345;
    cout << sumOfDigits(n);
    return 0;
}