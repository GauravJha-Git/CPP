// You are given an array arr[] of non-negative integers. Your task is to move all the zeros in the array to the right end while maintaining the relative order of the non-zero elements. The operation must be performed in place, meaning you should not use extra space for another array.

// Examples:

// Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
// Output: [1, 2, 4, 3, 5, 0, 0, 0]
// Explanation: There are three 0s that are moved to the end.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) { //here we are changing the value , not the copy (call by reference)
        int n = arr.size();
        int j = 0; // Position to place the next non-zero element
        
        // Traverse the array
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                swap(arr[i], arr[j]);
                j++; // Move the pointer forward
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array before pushing zeros to the end: \n";
    for (int i : arr) {
        cout << i << " ";
    }

    Solution obj;
    obj.pushZerosToEnd(arr);

    cout << "Array after pushing zeros to the end: \n";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
