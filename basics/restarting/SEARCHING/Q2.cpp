//recursively binary search

#include <iostream>
using namespace std;

// Recursive Binary Search Function
int binarySearchRecursive(int arr[], int start, int end, int key) {
    if (start > end)
        return -1;  // Base case: key not found

    int mid = (start + end) / 2;

    if (arr[mid] == key)
        return mid;  // Key found
    else if (key > arr[mid])
        return binarySearchRecursive(arr, mid + 1, end, key);  // Search right half
    else
        return binarySearchRecursive(arr, start, mid - 1, key);  // Search left half
}

int main() {
    int size, key;

    cout << "Enter the size of the sorted array: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " sorted elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter the key to search: ";
    cin >> key;

    int result = binarySearchRecursive(arr, 0, size - 1, key);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Key not found in the array." << endl;

    return 0;
}
