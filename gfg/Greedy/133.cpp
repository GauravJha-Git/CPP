/*
---------------------------------------
QUESTION:
---------------------------------------
You are given the arrival times arr[] and departure times dep[] of all trains 
that arrive at a railway station on the same day. 
Find the minimum number of platforms needed so that no train has to wait.

At any given time, the same platform cannot be used for both arrival and departure.
If two trains arrive at the same time, or if one arrives before another departs, 
additional platforms are needed.

Examples:
Input: 
arr[] = [900, 940, 950, 1100, 1500, 1800]
dep[] = [910, 1200, 1120, 1130, 1900, 2000]
Output: 3

Input:
arr[] = [900, 1235, 1100]
dep[] = [1000, 1240, 1200]
Output: 1

Constraints:
1 ≤ number of trains ≤ 50000
0000 ≤ arr[i] ≤ dep[i] ≤ 2359
---------------------------------------
APPROACH:
---------------------------------------
We will solve this using the Two Pointer Technique:
1. Sort both arrival and departure arrays.
2. Use two pointers i (arrivals) and j (departures).
3. If arr[i] <= dep[j], it means a train arrives before earliest departure -> 
   need +1 platform, move to next arrival.
4. Else, a train departs -> free a platform (-1), move to next departure.
5. Keep track of the maximum platforms needed at any point.

Time Complexity: O(n log n)  (due to sorting)
Space Complexity: O(1)
---------------------------------------
EXAMPLE:
---------------------------------------
arr = [900, 940, 950, 1100, 1500, 1800]
dep = [910, 1200, 1120, 1130, 1900, 2000]

Sorted:
arr = [900, 940, 950, 1100, 1500, 1800]
dep = [910, 1120, 1130, 1200, 1900, 2000]

Process:
900 <= 910  -> platforms=1 (max=1)
940 <= 910  -> No, departure -> platforms=0
940 <= 1120 -> platforms=1 (max=1)
950 <= 1120 -> platforms=2 (max=2)
1100 <= 1120-> platforms=3 (max=3)
... Answer = 3
---------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the minimum number of platforms required
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        
        // Sort arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 0, j = 0;
        int platform_needed = 0, max_platforms = 0;
        
        // Process all arrivals and departures
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) { // Train arrives before earliest departure
                platform_needed++;
                max_platforms = max(max_platforms, platform_needed);
                i++;
            } else { // Train departs before next arrival
                platform_needed--;
                j++;
            }
        }
        
        return max_platforms;
    }
};

int main() {
    Solution obj;
    
    // Test case 1
    vector<int> arr1 = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep1 = {910, 1200, 1120, 1130, 1900, 2000};
    cout << "Minimum Platforms Needed: " << obj.findPlatform(arr1, dep1) << endl;
    
    // Test case 2
    vector<int> arr2 = {900, 1235, 1100};
    vector<int> dep2 = {1000, 1240, 1200};
    cout << "Minimum Platforms Needed: " << obj.findPlatform(arr2, dep2) << endl;
    
    // Test case 3
    vector<int> arr3 = {1000, 935, 1100};
    vector<int> dep3 = {1200, 1240, 1130};
    cout << "Minimum Platforms Needed: " << obj.findPlatform(arr3, dep3) << endl;
    
    return 0;
}

/*
---------------------------------------
CODE EXPLANATION:
---------------------------------------
- Sort arrival and departure arrays to process events in time order.
- Use two pointers to track current arrival and departure.
- If arrival happens before or at the same time as departure, increase platform count.
- Else, a departure happens -> decrease platform count.
- Keep track of the maximum platforms needed throughout.
- Return max_platforms as final answer.
---------------------------------------
*/
