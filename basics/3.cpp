#include<iostream>
using namespace std;
int main() {
    int num , original , reversed =0;

    original=num;

    while(num>0){
        int digit = num % 10;
        reversed = reversed*10+digit;
        num=num/10;
    }

    if(reversed==original){
        cout<<"The number is a palindrome"<<endl;
    }
    else{
        cout<<"The number is not palindrome"<<endl;
    }
return 0;
}