#include <iostream>
#include <unordered_map>
using namespace std;

string calculateFraction(int a, int b) {

    // If the numerator is zero, answer is 0
    if (a == 0)
        return "0";

    string res = "";

    // Handling sign without ternary operator
    bool isNegative = false;
    if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
        isNegative = true;
    }

    if (isNegative) {
        res += "-";
    }

    a = abs(a);
    b = abs(b);

    // Calculate and append the part before decimal point
    res += to_string(a / b);

    int rem = a % b;

    // If completely divisible, return res
    if (rem == 0)
        return res;

    res.append(".");
    unordered_map<int, int> mp;

    while (rem > 0) {

        // If this remainder is already seen,
        // then there exists a repeating fraction.
        if (mp.find(rem) != mp.end()) {
            res.insert(mp[rem], "(");
            res.append(")");
            break;
        }

        // If the remainder is seen for the first time,
        // store its index
        mp[rem] = res.size();

        rem = rem * 10;

        // Calculate quotient, append it to result and
        // calculate next remainder
        res += to_string(rem / b);
        rem = rem % b;
    }

    return res;
}

int main() {
    int a = 50, b = 22;
    cout << calculateFraction(a, b) << endl;
    return 0;
}
