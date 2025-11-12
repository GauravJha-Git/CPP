#include <bits/stdc++.h>
using namespace std;

/*
-----------------------------------------------
   Program: Check if two rectangles overlap
   Assumption: Rectangles are parallel to axes
-----------------------------------------------
*/

// Structure to represent a coordinate point
struct Point {
    int x, y;
};

// Function to check if two rectangles overlap
bool doOverlap(Point L1, Point R1, Point L2, Point R2) {
    // Case 1: One rectangle is completely to the left of the other
    if (L1.x > R2.x || L2.x > R1.x)
        return false;

    // Case 2: One rectangle is completely above the other
    if (R1.y > L2.y || R2.y > L1.y)
        return false;

    // Otherwise, rectangles overlap
    return true;
}

// Driver code
int main() {
    // Rectangle 1 coordinates
    Point L1 = {0, 10};   // Top-left corner
    Point R1 = {10, 0};   // Bottom-right corner

    // Rectangle 2 coordinates
    Point L2 = {5, 5};    // Top-left corner
    Point R2 = {15, 0};   // Bottom-right corner

    // Check if rectangles overlap
    if (doOverlap(L1, R1, L2, R2))
        cout << "Rectangles Overlap ✅" << endl;
    else
        cout << "Rectangles Do Not Overlap ❌" << endl;

    return 0;
}


// class Solution {
//   public:
//     int doOverlap(vector<int> L1, vector<int> R1, vector<int> L2, vector<int> R2) {
        
//         // If one rectangle is to the left of the other
//         if (L1[0] > R2[0] || L2[0] > R1[0])
//             return false;

//         // If one rectangle is above the other
//         if (R1[1] > L2[1] || R2[1] > L1[1])
//             return false;

//         return true;
//     }
// };
