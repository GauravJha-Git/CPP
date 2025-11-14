// C++ program to find the digit sum 
// using mathematical formula

#include <iostream>
using namespace std;

int singleDigit(int n) {
  
      // If given number is zero its
      // digit sum will be zero only
    if (n == 0) 
       return 0;
    
      // If result of modulo operation is 
      // zero then, the digit sum is 9
      if(n % 9 == 0)
          return 9;
     
      return (n % 9);
}

int main() {
    int n = 1234;
    cout << singleDigit(n);
    return 0;
}