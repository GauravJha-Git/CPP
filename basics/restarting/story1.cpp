// You are opening a tea stall. Each chai costs ₹7.
// Write a program that:

// Takes the total money from the user.

// Calculates how many chais they can buy and how much money will be left.

// Input: ₹50
// Output: You can buy 7 chai(s) and ₹1 will be left.
// code-
#include<iostream>
using namespace std;

int main (){
    int money,chai,remaining;
    cout<<"Enter the money: ";
    cin>>money;
    chai = money/7;
    remaining = money%7;
    cout<<"You can buy "<<chai<<" chai and "<<remaining<<" will be left.";
    return 0;
}