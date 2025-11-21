#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> printDivisors(int n) {
    vector<int>divisors;
    
    // Note that this loop runs till square root
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            
            // If divisors are equal, print only one
            if (n / i == i) {
                divisors.push_back(i) ;
            }
            // Otherwise print both 
            else {
                divisors.push_back(i) ;
                divisors.push_back(n/i) ;
            }
        }
    }
    
    return divisors;
}

int main() {
    vector<int>divisors = printDivisors(10);
    for(auto &divs: divisors) {
        cout << divs << " " ;
    }
    return 0;
}