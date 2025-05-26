#include<iostream>
#include<array>
using namespace std;



int main(){
array<int,5> arr = {1,2,3,4,5};

int n= arr.size();

int sum = 0;

for(int i=0; i<n;i++){
    sum = sum+ arr[i];
}

cout<<sum<<endl;

int average = sum/n;

cout<<"average = "<<average<<endl;



int sum2= arr.front() + arr.back();  //sum of first and last element

cout<<"Sum of First and Last element = "<< sum2<<endl;


return 0;
}
