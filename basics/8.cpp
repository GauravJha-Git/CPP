#include<iostream>
#include<string>

using namespace std;
int main(){
    int arr[5];
    int max=arr[0];
    int min= arr[0];

    for(int i=0;i<5;i++){
        cout<<"enter " << i+1<<" element"<<endl;
        cin>>arr[i];
    }
    for(int i=0;i<5;i++){
        if(arr[i] > max ){
            max= arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }

    cout << "Maximum: " << max << endl;
    cout << "Minimum: " << min << endl;
    return 0;

}