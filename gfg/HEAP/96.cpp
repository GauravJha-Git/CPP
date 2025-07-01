/*
🔷 K Closest Points to Origin

📝 Problem:
Given an array of points where each point is represented as points[i] = [xi, yi] on the X-Y plane and an integer k,
return the k closest points to the origin (0, 0) using Euclidean distance.

Euclidean Distance: sqrt(x² + y²)
(Note: we use squared distance for comparison to avoid computing sqrt)

📥 Input Example:
points = [[1,3], [-2,2], [5,8], [0,1]], k = 2

📤 Output Example:
[[0,1], [-2,2]]

✅ Approach (Using Max Heap):
1. Use a max-heap (priority_queue) to store k closest points.
2. Compute squared distance for each point: x² + y².
3. Push each point to the heap. If heap size exceeds k, remove farthest point.
4. At the end, the heap contains the k closest points.

🧠 Time Complexity: O(n log k)
🧠 Space Complexity: O(k)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap to keep track of k closest points by distance
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (auto& point : points) {
            int x = point[0], y = point[1];
            int dist = x * x + y * y; // Squared distance (no sqrt needed)

            maxHeap.push({dist, point});

            // Maintain heap size to k
            if (maxHeap.size() > k) {
                maxHeap.pop(); // Remove the farthest point
            }
        }

        // Extract k closest points from heap
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;

    vector<vector<int>> closestPoints = sol.kClosest(points, k);

    cout << "The " << k << " closest points to the origin are:\n";
    for (auto& p : closestPoints) {
        cout << "[" << p[0] << ", " << p[1] << "]\n";
    }

    return 0;
}
