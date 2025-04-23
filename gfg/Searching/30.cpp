// Search in Rotated Sorted Array
// Difficulty: MediumAccuracy: 37.64%Submissions: 260K+Points: 4
// Given a sorted and rotated array arr[] of distinct elements, the task is to find the index of a target key. Return -1 if the key is not found.

// Examples :

// Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 3
// Output: 8
// Explanation: 3 is found at index 8.
// code-
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int search(vector<int>& arr, int key) {

        int low = 0, high = arr.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            
            if(arr[mid]==key)return mid;
            
            if(arr[low]<=arr[mid]){
                if(arr[low]<=key && key<=arr[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            else{
                if(arr[mid]<key && key<=arr[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
