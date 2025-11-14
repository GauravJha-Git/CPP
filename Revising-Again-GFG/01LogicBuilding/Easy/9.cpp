//fibbonacci number using space optimization

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the nth Fibonacci number
// using space optimization
int nthFibonacci(int n){

    if (n <= 1) return n;

    // To store the curr Fibonacci number
    int curr = 0;

    // To store the previous Fibonacci number
    int prev1 = 1;
    int prev2 = 0;

    // Loop to calculate Fibonacci numbers from 2 to n
    for (int i = 2; i <= n; i++){

        // Calculate the curr Fibonacci number
        curr = prev1 + prev2;

        // Update prev2 to the last Fibonacci number
        prev2 = prev1;

        // Update prev1 to the curr Fibonacci number
        prev1 = curr;
    }

    return curr;
}


int main() {
    int n = 5;
    int result = nthFibonacci(n);
    cout << result << endl;
    
    return 0;
}