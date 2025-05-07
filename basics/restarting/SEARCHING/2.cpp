// Binary Search
// ✅ Concept Recap:
// Binary Search works only on sorted arrays.

// It keeps dividing the search range in half:

// If the middle element is the key → return index.

// If the key is greater → search in the right half.

// If the key is smaller → search in the left half.
#include <iostream>
using namespace std;

// Binary Search Function
int binarySearch(int arr[], int size, int key) {
    int start = 0, end = size - 1;

    while(start <= end) {
        int mid = (start + end) / 2;

        // Check if key is at mid
        if(arr[mid] == key) 
            return mid;

        // If key is greater, ignore left half
        else if(key > arr[mid]) 
            start = mid + 1;

        // If key is smaller, ignore right half
        else 
            end = mid - 1;
    }

    // Key not found
    return -1;
}

int main() {
    int size, key;

    cout << "Enter the size of the sorted array: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " sorted elements: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter the key to search: ";
    cin >> key;

    int result = binarySearch(arr, size, key);

    if(result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Key not found in the array." << endl;

    return 0;
}
