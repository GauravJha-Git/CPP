//Factorial of a number

#include <iostream>
using namespace std;

int factorial(int n) {
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            // calculating the factorial
            ans = ans * i;
        }
        return ans;
    }

int main()
{
    int num = 5;
    cout <<  factorial(num) << endl;
    return 0;
}