#include <iostream>
#include <cmath>
using namespace std;

int floorSqrt(int n) {
    
  	// square root using sqrt function, it returns
  	// the double value, which is casted to integer
  	int res = sqrt(n);
  	// use sqrtl for big numbers
  	return res;
}

int main() {
    int n = 11;
    cout << floorSqrt(n);
    return 0;
}