#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if number (given as string) is divisible by 4
    int divisibleBy4(string N) {
        int len = N.length();

        // If number has only 1 digit
        // Just check that single digit
        if (len == 1) {
            int x = N[0] - '0';   // convert char to int
            return (x % 4 == 0);  // return 1 if divisible, else 0
        }

        // Take last two digits of the number
        // Example: N = "1234"
        // last two digits = '3' and '4'
        int last = (N[len - 2] - '0') * 10    // tens place
                 + (N[len - 1] - '0');       // ones place

        // If last two digits % 4 == 0 → whole number divisible by 4
        return (last % 4 == 0);
    }
};

int main() {
    Solution obj;

    string N;
    cout << "Enter number: ";
    cin >> N;

    if (obj.divisibleBy4(N)) {
        cout << "Divisible by 4\n";
    } else {
        cout << "Not divisible by 4\n";
    }

    return 0;
}
