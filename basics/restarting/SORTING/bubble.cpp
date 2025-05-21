// #include <iostream>
// using namespace std;

// int main() {
//     int arr[] = {5, 2, 9, 1, 6};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     // Bubble Sort
//     for (int i = 0; i < n - 1; i++) {
//         // Last i elements are already in place
//         for (int j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 // swap arr[j] and arr[j+1]
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }

//     // Print the sorted array
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }
#include <iostream>
using namespace std;

// Bubble Sort function
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n); // Call the sorting function

    // Print sorted array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
