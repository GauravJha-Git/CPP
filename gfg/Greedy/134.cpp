/*
📌 Activity Selection Problem

🔹 Question:
You are given n activities, each with a start time and a finish time, represented by arrays start[] and finish[].
A person can perform only one activity at a time, meaning no two activities can overlap.

Find the maximum number of activities that a person can complete in a day.

🔹 Example 1:
Input:
start[]  = [1, 3, 0, 5, 8, 5]
finish[] = [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: Activities chosen = {0, 1, 3, 4}

🔹 Example 2:
Input:
start[]  = [10, 12, 20]
finish[] = [20, 25, 30]
Output: 1

🔹 Constraints:
1 ≤ n ≤ 2*10^5
0 ≤ start[i] ≤ finish[i] ≤ 10^9
*/

/*
🔹 Approach (Greedy):
1. Pair each activity as {finish, start}.
2. Sort activities by finish time (earliest finish first).
3. Select the first activity.
4. For each next activity, select it only if start > lastFinish (strictly greater).
5. Count how many activities are selected.
*/

/*
🔹 Example Walkthrough:
start  = [1, 3, 0, 5, 8, 5]
finish = [2, 4, 6, 7, 9, 9]

Activities as {finish, start}:
{(2,1), (4,3), (6,0), (7,5), (9,8), (9,5)}

After sorting:
{(2,1), (4,3), (6,0), (7,5), (9,5), (9,8)}

Pick (2,1) ✅
(4,3) starts after 2 → pick ✅
(6,0) starts before 4 → skip ❌
(7,5) starts after 4 → pick ✅
(9,5) starts before 7 → skip ❌
(9,8) starts after 7 → pick ✅

Total selected = 4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();
        if (n == 0) return 0;

        vector<pair<int,int>> activities;
        activities.reserve(n);

        // Store activities as {finish, start}
        for (int i = 0; i < n; ++i) {
            activities.emplace_back(finish[i], start[i]);
        }

        // Sort by finish time
        sort(activities.begin(), activities.end());

        int count = 1;
        int lastFinish = activities[0].first;

        // Greedy selection
        for (int i = 1; i < n; ++i) {
            if (activities[i].second > lastFinish) { // strict condition
                count++;
                lastFinish = activities[i].first;
            }
        }
        return count;
    }
};

int main() {
    Solution obj;

    // Example 1
    vector<int> start1 = {1, 3, 0, 5, 8, 5};
    vector<int> finish1 = {2, 4, 6, 7, 9, 9};
    cout << obj.activitySelection(start1, finish1) << endl;  // Output: 4

    // Example 2
    vector<int> start2 = {10, 12, 20};
    vector<int> finish2 = {20, 25, 30};
    cout << obj.activitySelection(start2, finish2) << endl;  // Output: 1

    // Example 3 (edge case)
    vector<int> start3 = {2, 1};
    vector<int> finish3 = {2, 2};
    cout << obj.activitySelection(start3, finish3) << endl;  // Output: 1

    return 0;
}

/*
🔹 Code Explanation:
- Store activities as {finish, start} for easy sorting by finish time.
- Always pick the first activity (earliest finish).
- For each next activity, if start > lastFinish → pick it.
- Return the total count.

🔹 Complexity:
Time: O(N log N) due to sorting
Space: O(N) for storing pairs
*/
