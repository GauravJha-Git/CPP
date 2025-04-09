#include<iostream>

using namespace std;
int main(){
    int n,reversed=0;

    cout<<"enter a number:";
    cin>>n;


    while(n>0){
        int digit = n%10;
        reversed= reversed*10+digit;
        n=n/10;
    }

    cout<<"reversed number:"<<reversed;
    return 0;

}