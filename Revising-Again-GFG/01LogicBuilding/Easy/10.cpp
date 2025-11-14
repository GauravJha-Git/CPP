//binary representation of a number

#include <iostream>
#include <algorithm>
using namespace std;

string decToBinary(int n) {
    
    string bin = "";
    while (n > 0) {
        // checking the mod 
		int bit = n%2;
      	bin.push_back('0' + bit);  // convert int -> char

        n /= 2; // reduce n
    }
    
    // reverse the string 
	reverse(bin.begin(), bin.end()); // reverse for correct order
    return bin;
}


int main() {
    int n = 12;
    cout << decToBinary(n);
    return 0;
}