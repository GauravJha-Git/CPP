
#include <iostream>
using namespace std;

// Selection Sort function
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
    
        swap(arr[i], arr[maxIndex]);
    }
}

int main() {
    int arr[] = {1,9,3,7,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n); // Call the sorting function

    // Print the sorted array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
