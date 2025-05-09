#include<iostream>
using namespace std;

int factorial(int n){
    int result = 1;
    for(int i = 1 ;i<=n ;i++ ){
        result = result*i;
    }

    return result;

}


int main(){

    cout<<factorial(100); //this will find the factorial of given number

return 0;
}