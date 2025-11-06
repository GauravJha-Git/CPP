// Closest Number
// Difficulty: BasicAccuracy: 15.77%Submissions: 126K+Points: 1
// Given two integers n and m (m != 0). The problem is to find the number closest to n and divisible by m. If there is more than one such number, then output the one having the maximum absolute value.
// optimized approach

#include <iostream>
#include <cmath>
using namespace std;

int closestNumber(int n, int m) {
    int q = n / m;          // integer quotient
    int n1 = m * q;         // multiple below or equal to n

    // second possible multiple
    int n2 = (n * m > 0) ? (m * (q + 1)) : (m * (q - 1));

    // pick the closer one
    if (abs(n - n1) < abs(n - n2))
        return n1;
    else if (abs(n - n1) > abs(n - n2))
        return n2;
    else
        return (abs(n1) > abs(n2)) ? n1 : n2; // tie → larger abs value
}

int main() {
    int n = -15, m = 6;
    cout << closestNumber(n, m) << endl;
    return 0;
}
