#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int arr[n];

    for(int i=0 ; i<n ;i++){
        cout<<"enter "<<i+1<<" element: "<<endl;
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        cout<<"element " <<i+1<< " is "<<arr[i]<<endl;
    }

    int choice; bool found=false;
    cout<<"Enter the number to find: ";
    cin>>choice;

    for(int i=0 ; i<n ;i++){
        if (arr[i]==choice)
        {
            cout<<"Found "<<choice <<" at index "<< i+1;
            found = true;
            break;
        }
        
        
    }

    if(!found){
        cout << "The element doesnot exist" << endl;
    }

    return 0;
    
}