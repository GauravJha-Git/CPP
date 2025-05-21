// Pick the smallest element in the unsorted part and place it at the beginning.
#include <iostream>
using namespace std;

// Selection Sort function
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum with the first element
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[] = {7, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n); // Call the sorting function

    // Print the sorted array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
