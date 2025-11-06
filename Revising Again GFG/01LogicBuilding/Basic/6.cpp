// Closest Number
// Difficulty: BasicAccuracy: 15.77%Submissions: 126K+Points: 1
// Given two integers n and m (m != 0). The problem is to find the number closest to n and divisible by m. If there is more than one such number, then output the one having the maximum absolute value.
// naive approach

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int closestNumber(int n, int m) {
    int closest = 0;
    int minDiff = INT_MAX;

    // check numbers around n (within one multiple of m)
    for (int i = n - abs(m); i <= n + abs(m); ++i) {
        if (i % m == 0) { // divisible by m
            int diff = abs(n - i);

            // update if this is closer OR same distance but larger abs value
            if (diff < minDiff || 
               (diff == minDiff && abs(i) > abs(closest))) {
                closest = i;
                minDiff = diff;
            }
        }
    }
    return closest;
}

int main() {
    int n = 13, m = 4;
    cout << closestNumber(n, m) << endl;
    return 0;
}
