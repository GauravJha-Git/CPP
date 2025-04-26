// Aggressive Cows
// Difficulty: MediumAccuracy: 59.57%Submissions: 123K+Points: 4Average Time: 30m
// You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

// Examples :

// Input: stalls[] = [1, 2, 4, 8, 9], k = 3
// Output: 3
// Explanation: The first cow can be placed at stalls[0], 
// the second cow can be placed at stalls[2] and 
// the third cow can be placed at stalls[3]. 
// The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.
// Here’s the simple idea:

// You want to maximize the minimum distance between any two cows.

// So, you binary search the answer: the minimum distance.

// Steps:
// Sort the stalls array.

// Binary search on the distance:

// low = 1 (smallest possible distance),

// high = (maximum stall position - minimum stall position).

// For each mid (possible distance), check if you can place all k cows with at least mid distance apart.

// If yes, try for a bigger distance.

// If no, try a smaller distance.
// code-

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPlace(vector<int>& stalls, int k, int minDist) {
        int cows = 1;
        int lastPos = stalls[0];
        
        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - lastPos >= minDist) {
                cows++;
                lastPos = stalls[i];
            }
            if(cows == k) return true;
        }
        
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        
        int low = 1;
        int high = stalls.back() - stalls.front();
        int ans = 0;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;  // safer way to calculate mid
            
            if(canPlace(stalls, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};


int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

