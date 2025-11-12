// C++ program to count pairs whose sum cubes is n
#include<bits/stdc++.h>
using namespace std;

int countPairs(int n) {
    int count = 0;

    // Check for each number 1 to cbrt(n)
    for (int i = 1; i <= cbrt(n); i++)  {
        // Store cube of a number
        int cb = i*i*i;

        // Subtract the cube from given N
        int diff = n - cb;

        // Check if the difference is also
        // a perfect cube
        int cbrtDiff = cbrt(diff);

        // If yes, then increment count
        if (cbrtDiff*cbrtDiff*cbrtDiff == diff)
            count++;
    }

    return count;
}

int main() {
 		int n = 9;
        cout << countPairs(n) <<"\n";

    return 0;
}