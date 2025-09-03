/*
📌 Problem Statement:
You are given `n` houses represented by their 2D coordinates in a city.
The cost of connecting two houses is defined as their Manhattan Distance:

    Cost(i,j) = |x_i - x_j| + |y_i - y_j|

Your task is to connect all houses such that the total cost is minimized.

This is equivalent to building a Minimum Spanning Tree (MST) where:
- Vertices = houses
- Edge weights = Manhattan distances

-------------------------------------------------------------
✅ Example 1:
Input:
n = 5
houses = [[0, 7], [0, 9], [20, 7], [30, 7], [40, 70]]

Output:
105

Explanation:
Connect (0,7) → (0,9) with cost = 2
Connect (0,7) → (20,7) with cost = 20
Connect (20,7) → (30,7) with cost = 10
Connect (30,7) → (40,70) with cost = 73
Total = 105

✅ Example 2:
Input:
n = 4
houses = [[0, 0], [1, 1], [1, 3], [3, 0]]

Output:
7

Explanation:
Connect (0,0) → (1,1) with cost = 2
Connect (1,1) → (1,3) with cost = 2
Connect (0,0) → (3,0) with cost = 3
Total = 7
-------------------------------------------------------------

🔑 Approach:
This is a Minimum Spanning Tree (MST) problem.
We solve it using Prim’s Algorithm:
1. Start from any house.
2. Always pick the cheapest edge to a new house (using a min-heap).
3. Mark houses as visited when connected.
4. Stop when all houses are connected.

-------------------------------------------------------------
📘 Algorithm:
1. Initialize `visited[] = false` for all houses.
2. Push (0,0) into a min-heap (cost, house_index).
3. While not all houses are connected:
   - Pop the edge with the smallest cost.
   - If house already visited, skip.
   - Otherwise, mark visited, add cost to totalCost.
   - Push edges from this house to all unvisited houses.
4. Return totalCost.
-------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        
        // Manhattan distance between two houses
        auto manhattan = [&](int i, int j) {
            return abs(houses[i][0] - houses[j][0]) + abs(houses[i][1] - houses[j][1]);
        };
        
        vector<bool> visited(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0, 0}); // start with house 0, cost 0
        int totalCost = 0, count = 0;
        
        while (count < n) {
            auto [cost, u] = pq.top();
            pq.pop();
            
            if (visited[u]) continue; // already connected
            
            visited[u] = true;
            totalCost += cost;
            count++;
            
            // push edges from u to all unvisited houses
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    pq.push({manhattan(u, v), v});
                }
            }
        }
        
        return totalCost;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> houses1 = {{0, 7}, {0, 9}, {20, 7}, {30, 7}, {40, 70}};
    cout << "Minimum Cost (Example 1): " << sol.minCost(houses1) << endl; // Expected: 105

    vector<vector<int>> houses2 = {{0, 0}, {1, 1}, {1, 3}, {3, 0}};
    cout << "Minimum Cost (Example 2): " << sol.minCost(houses2) << endl; // Expected: 7

    return 0;
}

/*
-------------------------------------------------------------
🔎 Code Explanation:
- manhattan(i,j): computes Manhattan distance between house i and j.
- visited[]: keeps track of houses already connected.
- pq: a min-heap storing (cost, house) to always pick the smallest edge.
- totalCost: accumulates the minimum total cost.
- Loop continues until all houses are connected.

-------------------------------------------------------------
⏱️ Complexity:
- Time: O(n^2 log n), since for each house we may push up to n edges into the heap.
- Space: O(n^2) in the worst case for the heap.
- Works efficiently for n ≤ 1000.

*/
