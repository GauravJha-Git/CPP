// Count Inversions
// Difficulty: MediumAccuracy: 16.93%Submissions: 649K+Points: 4
// Given an array of integers arr[]. Find the Inversion Count in the array.
// Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum. 

// Examples:

// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
// ✅ Key Concept:
// During the merge step of merge sort, if an element from the right half is placed before an element in the left half, it means all remaining elements in the left half form inversions with that element.

// 🔍 Example:
// For arr = [2, 4, 1, 3, 5]

// Inversions are:

// (2, 1)

// (4, 1)

// (4, 3)

// Total: 3
// code-
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to count inversions in the array.
    long long merge(vector<int>&arr , vector<int>& temp, int left , int mid , int right){
        long long inv_count = 0;
        int i=left;
        int j = mid+1;
        int k= left;
        
        while(i<=mid && j<=right){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
                
            }else{
                temp[k++]= arr[j++];
                inv_count += (mid-i+1);
            }
        }
        while(i<=mid) temp[k++]=arr[i++];
        while(j<=right) temp[k++]=arr[j++];
        for(int idx=left; idx<=right; idx++) arr[idx]=temp[idx];
        
        return inv_count;
    }
    
    long long mergeSort(vector<int>&arr, vector<int> &temp, int left , int right){
        long long inv_count = 0;
        if(left<right){
            int mid=(left+right)/2;
            inv_count += mergeSort(arr,temp,left,mid);
            inv_count += mergeSort(arr,temp,mid+1,right);
            inv_count += merge(arr,temp,left,mid,right);
        }
        
        return inv_count;
    }
    
    
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        vector<int> temp(arr.size());
        return mergeSort(arr,temp,0,arr.size()-1);
        
    }
};




int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

