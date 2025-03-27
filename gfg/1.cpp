#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    // Function returns the second
    // largest element
    int getSecondLargest(vector<int> &arr) { //vector<int> is a dynamic array of integers , &arr this means we are passing array by reference not value 
        //Why Use vector<int>?
            // A vector in C++ is a dynamic array that can:

            // Grow or shrink in size automatically.

            // Provide easy indexing like an array (arr[i]).

            // Offer built-in methods like .size(), .push_back(), etc.



            // we are using vector to use array dynamically , and calling it by reference so that original array is changed not its copy , which saves our memory
        int largest = -1, secondLargest = -1;
        
        for (int num : arr) {
            if (num > largest) {
                secondLargest = largest;
                largest = num;
            } else if (num > secondLargest && num < largest) {
                secondLargest = num;
            }
        }
        
        return secondLargest;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Second largest element: " << sol.getSecondLargest(arr) << endl;
    return 0;
}