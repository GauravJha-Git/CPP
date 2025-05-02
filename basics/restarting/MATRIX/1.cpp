#include<iostream>

using namespace std;

int main(){
    int arr[5]={5,4,7,8,6};
    int sum=0;
    int maxElement = arr[0];
    int minElement = arr[0];
    for(int i=0; i<5; i++){
        cout<<arr[i]<<";";
        sum = sum + arr[i];

        if(arr[i] > maxElement) {
            maxElement = arr[i];
        }
        if(arr[i] < minElement) {
            minElement = arr[i];
        }

    }


    int start = 0;
    int end = 4;
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    // Print reversed array
    cout << "\nReversed array: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    // for (int start = 0, end = length - 1; start < length / 2; start++, end--) {
    //     swap(arr[start], arr[end]);
    // }


    


    cout<<"\nMax Element : "<<maxElement<<endl;
    cout<<"Min Element : "<<minElement<<endl;
    cout<<"Sum: "<<sum<<endl;

    return 0;


}