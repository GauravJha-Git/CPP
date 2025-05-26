// C++ Program: Insertion Sort with Shift Count and User Input
#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int insertionSort(int arr[], int n) {
    int shiftCount = 0;

    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements to the right
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            shiftCount++; // Count this shift
        }

        arr[j + 1] = key;

        cout << "Pass " << i << ": ";
        printArray(arr, n);
    }

    return shiftCount;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Original array: ";
    printArray(arr, n);

    int totalShifts = insertionSort(arr, n);

    cout << "Total number of shifts: " << totalShifts << endl;

    return 0;
}
