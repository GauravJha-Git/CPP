#include <bits/stdc++.h>
using namespace std;

/*
    🚗 Gas Station Problem

    Question:
    There are some gas stations along a circular route.
    You are given two integer arrays:
    - gas[] : amount of gas at each station
    - cost[] : cost of traveling to the next station

    You start with 0 gas and an unlimited tank.
    Return the index of the starting station if you can travel around the circuit once in a clockwise direction.
    If no such station exists, return -1.

    Note: If a solution exists, it is guaranteed to be unique.
*/

class Solution {
public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int totalGas = 0, totalCost = 0;
        int start = 0, tank = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];

            // If tank goes negative, reset start
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        // If total gas < total cost, it's impossible
        return (totalGas < totalCost) ? -1 : start;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> gas1 = {4, 5, 7, 4};
    vector<int> cost1 = {6, 6, 3, 5};
    cout << "Output 1: " << sol.startStation(gas1, cost1) << endl; // Expected: 2

    // Example 2
    vector<int> gas2 = {1, 2, 3, 4, 5};
    vector<int> cost2 = {3, 4, 5, 1, 2};
    cout << "Output 2: " << sol.startStation(gas2, cost2) << endl; // Expected: 3

    // Example 3
    vector<int> gas3 = {3, 9};
    vector<int> cost3 = {7, 6};
    cout << "Output 3: " << sol.startStation(gas3, cost3) << endl; // Expected: -1

    return 0;
}

/*
📌 Approach:
1. If totalGas < totalCost → return -1 (impossible to travel).
2. Traverse all stations:
   - tank += gas[i] - cost[i]
   - If tank < 0 → reset tank = 0, start = i+1
3. Return start.

📌 Why this works:
- If you run out of gas at station i, then no earlier station could be the start,
  because they would reach i with even less gas.
- So the only possible start is after i.
- Greedy ensures O(n) solution.
*/
