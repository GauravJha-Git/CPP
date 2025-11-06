// Nth term of AP from First Two Terms
// Last Updated : 23 Jul, 2025
// Given two integers a1 and a2, the first and second terms of an Arithmetic Series respectively, the problem is to find the nth term of the series. 
// Examples :

// Input : a1 = 2,  a2 = 3,  n = 4
// Output : 5
// Explanation : The series is 2, 3, 4, 5, 6, ....   , thus the 4th term is 5. 

// Input : a1 = 1, a2 = 3, n = 10
// Output : 19
// Explanation:  The series is: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21..... Thus,10th term is 19.
// Naive Approach : We can find the common difference d = a2 - a1. Now, we can keep adding d to a1 for (n-1) times to get the nth term of the series.
// #include <bits/stdc++.h>
// using namespace std;

// int nthTermOfAP(int a1, int a2, int n)
// {
//     int nthTerm = a1, d = a2 - a1;

//     for (int i = 1; i < n; i++){
//         nthTerm += d;
//     }
//     return nthTerm;
// }

// int main()
// {
//     int a1 = 2, a2 = 3;
//     int n = 4;

//     cout << nthTermOfAP(a1, a2, n);
//     return 0;
// }

// optimal 
#include <bits/stdc++.h>
using namespace std;

int nthTermOfAP(int a1, int a2, int n)
{
    // using formula to find the
    // Nth term t(n) = a(1) + (n-1)*d
    return (a1 + (n - 1) * (a2 - a1));
}

int main()
{
    int a1 = 2, a2 = 3;
    int n = 4;
    cout << nthTermOfAP(a1, a2, n);
    return 0;
}