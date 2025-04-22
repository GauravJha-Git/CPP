// Sorted and Rotated Minimum
// Difficulty: EasyAccuracy: 40.57%Submissions: 145K+Points: 2
// A sorted array of distinct elements arr[] is rotated at some unknown point, the task is to find the minimum element in it. 

// Examples:

// Input: arr[] = [5, 6, 1, 2, 3, 4]
// Output: 1
// Explanation: 1 is the minimum element in the array.
// code-

#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int low = 0 , high = arr.size()-1;
        
        while(low<high){
            int mid = low + (high -low)/2;
            
            if(arr[mid]>arr[high]){
                low = mid+1;
            }
            else{
                high=mid;
            }
        }
        
        return arr[low];
    }
};


int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts); // or use: stringstream(ts) >> t;

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}
