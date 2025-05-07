// linear search in array
#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return i;

        }
    }
    return -1;
}

int main(){
    int size, key;

    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " elements: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter the key to search: ";
    cin >> key;

    int result = linearSearch(arr, size, key);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Key not found" << endl;

    return 0;

}