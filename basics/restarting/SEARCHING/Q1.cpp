#include<iostream>
using namespace std;


int linearSearch(int arr[],int size, int key){
    for(int i =0 ; i<size;i++){
        if(arr[i]==key){
            return i;
        }
    }

    return -1;
}


int main(){

    int size;

    cout<<"Enter Size of Array: ";
    cin>>size;

    int arr[size];


    cout<<"Enter Elements of Array"<<endl;
    for(int i =0; i<size;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter Element to find: ";
    cin>>key;

    int result= linearSearch(arr,size,key);

    if(result != -1){
        cout<<"Element Found at index "<<result+1<<"."<<endl;
    }else{
        cout<<"key not found !!!";
    }

}