// Efficiently compute (x^n) % m using Exponentiation by Squaring

// Step by step approach:

// Start with the result as 1.
// Use a loop that runs while the exponent n is greater than 0.
// If the current exponent is odd, multiply the result by the current base and apply the modulo.
// Square the base and take the modulo to keep the value within bounds.
// Divide the exponent by 2 (ignore the remainder).
// Repeat the process until the exponent becomes 0.

#include<iostream>
using namespace std;

int powMod(int x, int n, int M) {
    int res = 1;

    // Loop until exponent becomes 0
    while(n >= 1) {
        
        // n is odd, multiply result by current x and take modulo
        if(n & 1) {
            res = (res * x) % M;
            
            // Reduce exponent by 1 to make it even
            n--;  
        }
        
        // n is even, square the base and halve the exponent
        else {
            x = (x * x) % M;
            n /= 2;
        }
    }
    return res;
}

int main() {
    int x = 3, n = 2, M = 4;
    cout << powMod(x, n, M) << endl;
}



