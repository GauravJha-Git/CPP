// Overlapping Intervals
// Difficulty: MediumAccuracy: 57.41%Submissions: 98K+Points: 4
// Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.

// Examples:

// Input: arr[][] = [[1,3],[2,4],[6,8],[9,10]]
// Output: [[1,4], [6,8], [9,10]]
// Explanation: In the given intervals we have only two overlapping intervals here, [1,3] and [2,4] which on merging will become [1,4]. Therefore we will return [[1,4], [6,8], [9,10]].
// ✅ Approach:
// Sort intervals by start time.

// Use a stack or result vector to merge overlapping intervals:

// If the current interval overlaps with the last added interval → merge them.

// Else, just add the interval to the result.

// code-
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
 
      
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {

    sort(arr.begin(),arr.end());
      
      vector<vector<int>> merged;
      
      for(auto interval:arr){
          if(merged.empty()||merged.back()[1]<interval[0]){
              merged.push_back(interval);
          }else{
              merged.back()[1]=max(merged.back()[1], interval[1]);
          }
      }
      
      return merged;
    }
  };


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
