#include <iostream>
#include <iomanip>
using namespace std;

/*
----------------------------------------------
✅ Question: Implement Pow

Implement the function `power(b, e)` which calculates b raised to the power of e (i.e., b^e) without using built-in pow() function.

Constraints:
- -100.0 < b < 100.0
- -10^9 <= e <= 10^9
- Either b is not zero OR e > 0
- The result lies within the range [-10^4, 10^4]

Examples:
Input: b = 3.00000, e = 5         ➤ Output: 243.00000
Input: b = 0.55000, e = 3         ➤ Output: 0.16638
Input: b = -0.67000, e = -7       ➤ Output: -16.49971
----------------------------------------------

🧠 Approach: Exponentiation by Squaring
- Efficiently computes power in O(log e) time.
- Handles both positive and negative exponents.

📘 Explanation:
1. If e == 0 ➝ return 1.0
2. If e < 0 ➝ invert b and make e positive
3. While e > 0:
   - If e is odd, multiply result with b
   - Square b and halve e
4. Return the result

----------------------------------------------
*/

class Solution {
  public:
    double power(double b, int e) {
        // Base case: anything raised to 0 is 1
        if (e == 0) return 1.0;

        // Convert e to long long to handle INT_MIN
        long long exp = e;
        if (exp < 0) {
            b = 1 / b;
            exp = -exp;
        }

        double result = 1.0;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result *= b; // Multiply result when exponent is odd
            }
            b *= b;      // Square the base
            exp /= 2;    // Halve the exponent
        }

        return result;
    }
};

// -------- Main function for testing --------
int main() {
    Solution sol;

    // Test cases
    cout << fixed << setprecision(5);
    cout << "Test 1: power(3.00000, 5) = " << sol.power(3.00000, 5) << endl;
    cout << "Test 2: power(0.55000, 3) = " << sol.power(0.55000, 3) << endl;
    cout << "Test 3: power(-0.67000, -7) = " << sol.power(-0.67000, -7) << endl;

    return 0;
}
