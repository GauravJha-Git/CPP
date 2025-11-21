// calculate nCr (n choose r)

#include <iostream>
using namespace std;
int nCr(int n, int r){
    
    double sum = 1;

    // Calculate the value of n choose
    // r using the binomial coefficient formula
    for (int i = 1; i <= r; i++){
        
        sum = sum * (n - r + i) / i;
    }
    return (int)sum;
}
int main(){
    
    int n = 5;
    int r = 2;
    cout << nCr(n, r);

    return 0;
}