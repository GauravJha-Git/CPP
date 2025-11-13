//GCD or HCF (Using Euclid's Algorithm)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    Solution obj;
    int result = obj.gcd(a, b);

    cout << "GCD = " << result << endl;

    return 0;
}
