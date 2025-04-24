// Peak element
// Difficulty: BasicAccuracy: 38.86%Submissions: 549K+Points: 1Average Time: 30m
// Given an array arr[] where no two adjacent elements are same, find the index of a peak element. An element is considered to be a peak if it is greater than its adjacent elements (if they exist). If there are multiple peak elements, return index of any one of them. The output will be "true" if the index returned by your function is correct; otherwise, it will be "false".

// Note: Consider the element before the first element and the element after the last element to be negative infinity.

// Examples :

// Input: arr = [1, 2, 4, 5, 7, 8, 3]
// Output: true
// Explanation: arr[5] = 8 is a peak element because arr[4] < arr[5] > arr[6].
// code-
#include <bits/stdc++.h>
using namespace std;




class Solution {
  public:
    int peakElement(vector<int> &arr) {

        int n = arr.size();
        int low = 0, high = n-1;
        while(low<=high){
            int mid = low +(high-low)/2;
            
            int left = (mid==0)?INT_MIN:arr[mid-1];
            int right = (mid==n-1)?INT_MIN:arr[mid+1];
            
            if(arr[mid]>left && arr[mid]>right)
                return mid;
            else if(arr[mid]<right)
                low=mid+1;
            else
                high = mid-1;
        }
        return -1; 
    }
};



int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int idx = ob.peakElement(a);
        int n = a.size();
        bool f = 0;
        if (idx < 0 and idx >= n)
            cout << "false" << endl;
        else {
            if (n == 1 and idx == 0)
                f = 1;
            else if (idx == 0 and a[0] > a[1])
                f = 1;
            else if (idx == n - 1 and a[n - 1] > a[n - 2])
                f = 1;
            else if (a[idx] > a[idx + 1] and a[idx] > a[idx - 1])
                f = 1;
            else
                f = 0;
            if (f)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
