/*
  Job Sequencing Problem
  -----------------------
  You are given two arrays:
    - deadline[]: latest time by which a job should be finished
    - profit[]  : profit if job is finished before or on deadline

  Each job takes 1 unit of time and only one job can be scheduled at a time.

  Task:
    1. Find the maximum number of jobs that can be completed within their deadlines.
    2. Find the maximum profit earned by completing those jobs.

  Example:
    Input: deadline = [2, 1, 2, 1, 1], profit = [100, 19, 27, 25, 15]
    Output: [2, 127]
    Explanation: Job1 and Job3 are done → profit = 100 + 27 = 127

  Constraints:
    1 ≤ deadline.size() == profit.size() ≤ 10^5
    1 ≤ deadline[i] ≤ deadline.size()
    1 ≤ profit[i] ≤ 500

  ---------------------------------------------------
  Approach:
    1. Pair jobs as (profit, deadline).
    2. Sort jobs in descending order of profit (greedy approach).
    3. Find maximum deadline (max slot needed).
    4. Create a slot array to mark free slots.
    5. For each job in sorted list:
        - Try to place it at the latest available slot ≤ deadline.
        - If found, schedule job, increase count, add profit.
    6. Return [count, totalProfit].

  Time Complexity: O(N * maxDeadline) in worst case.
  ---------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        
        // Step 1: Pair jobs as {profit, deadline}
        vector<pair<int,int>> jobs;
        for(int i=0; i<n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }
        
        // Step 2: Sort jobs by profit (descending)
        sort(jobs.rbegin(), jobs.rend());
        
        // Step 3: Find maximum deadline
        int maxDeadline = 0;
        for(int d : deadline) {
            maxDeadline = max(maxDeadline, d);
        }
        
        // Step 4: Time slot array (initially empty)
        vector<int> slot(maxDeadline+1, -1);
        
        int countJobs = 0, totalProfit = 0;
        
        // Step 5: Greedy allocation
        for(int i=0; i<n; i++) {
            // Try placing job in the latest available slot
            for(int j=jobs[i].second; j>0; j--) {
                if(slot[j] == -1) {  // slot free
                    slot[j] = i;     // assign job
                    countJobs++;
                    totalProfit += jobs[i].first;
                    break;
                }
            }
        }
        
        return {countJobs, totalProfit};
    }
};

int main() {
    Solution obj;
    
    // Example 1
    vector<int> deadline1 = {4, 1, 1, 1};
    vector<int> profit1 = {20, 10, 40, 30};
    vector<int> ans1 = obj.jobSequencing(deadline1, profit1);
    cout << "Example 1: [" << ans1[0] << ", " << ans1[1] << "]\n";  // [2, 60]

    // Example 2
    vector<int> deadline2 = {2, 1, 2, 1, 1};
    vector<int> profit2 = {100, 19, 27, 25, 15};
    vector<int> ans2 = obj.jobSequencing(deadline2, profit2);
    cout << "Example 2: [" << ans2[0] << ", " << ans2[1] << "]\n";  // [2, 127]

    // Example 3
    vector<int> deadline3 = {3, 1, 2, 2};
    vector<int> profit3 = {50, 10, 20, 30};
    vector<int> ans3 = obj.jobSequencing(deadline3, profit3);
    cout << "Example 3: [" << ans3[0] << ", " << ans3[1] << "]\n";  // [3, 100]

    return 0;
}
