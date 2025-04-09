#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter a number:";
    cin >> n;
    if(n %2==0){
        cout<<"number is even";
    }else{
        cout<<"number is odd";
    }
    return 0;
}