#include<iostream>
using namespace std;

int main() {
    int arr[] = {7, 4, 10, 8, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int swapCount = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
            swap(arr[i], arr[minIndex]);
        // Only swap if needed
        if (minIndex != i) {
            //swap(arr[i], arr[minIndex]); this can be here too
            swapCount++;
        }
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nTotal Swaps: " << swapCount << endl;

    return 0;
}
