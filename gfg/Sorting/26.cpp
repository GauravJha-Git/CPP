// Merge Without Extra Space
// Difficulty: MediumAccuracy: 32.01%Submissions: 292K+Points: 4Average Time: 20m
// Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.

// Examples:

// Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
// Output:
// 2 2 3 4
// 7 10
// Explanation: After merging the two non-decreasing arrays, we get, 2 2 3 4 7 10
// 🔑 Idea:
// Compare and swap elements between arrays using a decreasing gap.

// Keep reducing the gap until it becomes 0.

// This ensures that both arrays remain sorted in-place.

// ✅ Steps:
// Define initial gap = ceil((n + m)/2)

// Compare elements a[i] and a[i+gap], a[i] and b[j], b[i] and b[i+gap]

// If a[i] > a[i+gap] → swap.

// Reduce gap: gap = ceil(gap / 2)

// Stop when gap = 0.
// code-
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size(), m = b.size();
        int gap = (n+m+1)/2;
        
        while(gap>0){
            int i = 0, j= gap;
            
            while(j<n+m){
                int val1 = (i<n)?a[i]:b[i-n];
                int val2 = (j<n)? a[j]:b[j-n];
                
                if(val1>val2){
                    if(i<n && j<n){
                        swap(a[i],a[j]);
                    }else if(i<n && j>=n){
                        swap(a[i],b[j-n]);
                    }else{
                        swap(b[i-n],b[j-n]);
                    }
                }
                i++;
                j++;
            }
            if(gap==1)break;
            gap=(gap+1)/2;
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
        cout << "~\n";
    }

    return 0;
}
