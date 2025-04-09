#include<iostream>
#include<string>

using namespace std;
int main(){
    int arr[5];

    for(int i=0;i<5;i++){
        cout<<"enter " << i+1<<" element"<<endl;
        cin>>arr[i];
    }
    for(int i=0;i<5;i++){
        cout<<"element " <<i+1<< " is "<<arr[i]<<endl;
    }
    return 0;

}