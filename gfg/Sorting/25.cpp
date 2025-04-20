// Non-overlapping Intervals

// Difficulty: MediumAccuracy: 51.92%Submissions: 35K+Points: 4Average Time: 30m
// Given a 2D array intervals[][] of representing intervals where intervals [i] = [starti, endi ]. Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Examples:

// Input: intervals[][] = [[1, 2], [2, 3], [3, 4], [1, 3]]
// Output: 1
// Explanation: [1, 3] can be removed and the rest of the intervals are non-overlapping.
// code-
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        sort(intervals.begin(),intervals.end(), [](const vector<int>&a, const vector<int> &b){
            return a[1]<b[1];
        });
        
        int count = 1;
        int end = intervals[0][1];
        
        for(int i=1; i<intervals.size();i++){
            if(intervals[i][0]>=end){
                count++;
                end = intervals[i][1];
            }
        }
        
        return intervals.size()-count;
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}