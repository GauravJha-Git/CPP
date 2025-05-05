#include<iostream>

using namespace std;


#include<iostream>
using namespace std;

void greetGaurav() {
    for(int i = 0; i < 5; i++) {
        cout << "Hello Gaurav!" << endl;
    }
}


int squareFun(int a){
    return a*a;
}


int number(int num){
    if(num%2 == 0){
        cout<<"even";
    }else{
        cout<<"odd";
    }
}


int main(){

        cout<<"Square of 5 :"<<squareFun(5)<<endl;
        greetGaurav();
        number(3);
        return 0;


}