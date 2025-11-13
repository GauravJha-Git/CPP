#include <iostream>
#include <algorithm>
using namespace std;

int lcm(int a, int b) {
    
    // larger value
    int g = max(a, b);
    
    // Smaller value
    int s = min(a, b);
    
    for (int i = g; i <= a * b; i += g) {
        if (i % s == 0)
            return i;
    }
}

int main() {
    int a = 10, b = 5;
    cout << lcm(a, b);
    return 0;
}