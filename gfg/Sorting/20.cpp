// sort 0s, 1s and 2s
// Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.

// You need to solve this problem without utilizing the built-in sort function.

// Examples:

// Input: arr[] = [0, 1, 2, 0, 1, 2]
// Output: [0, 0, 1, 1, 2, 2]
// Explanation: 0s 1s and 2s are segregated into ascending order.
// You can solve this problem efficiently using the Dutch National Flag algorithm by Edsger Dijkstra. This algorithm works in O(n) time and O(1) space.

// Approach:
// We use three pointers:

// low → tracks the position for 0

// mid → current element being processed

// high → tracks the position for 2


#include <bits/stdc++.h>
using namespace std;




class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int low = 0, mid = 0;
        int high = arr.size()-1;
        
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }
};


int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

