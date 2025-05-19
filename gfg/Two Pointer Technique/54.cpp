/*
📌 Question:
Given a sorted array `arr[]` and a target value `target`, count the number of pairs `(i, j)` such that:
- i < j
- arr[i] + arr[j] == target

💡 Example:
Input: arr = [-1, 1, 5, 5, 7], target = 6
Output: 3
Explanation: Pairs are (-1,7), (1,5), (1,5)

Input: arr = [1, 1, 1, 1], target = 2
Output: 6 (because 4C2 = 6)

--------------------------------------------------------

✅ Approach: Two Pointer Technique (Efficient for sorted arrays)
1. Initialize two pointers: left = 0, right = n-1
2. While left < right:
   a. If arr[left] + arr[right] == target
      - If values are equal: use formula nC2
      - Else: count duplicates on both sides and multiply
   b. If sum < target: move left++
   c. If sum > target: move right--
3. Return the total count

🧠 Time Complexity: O(n)
🧠 Space Complexity: O(1)

--------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int left = 0, right = arr.size() - 1;
        int count = 0;
        
        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == target) {
                // Case: All elements in range are equal
                if (arr[left] == arr[right]) {
                    int n = right - left + 1;
                    count += (n * (n - 1)) / 2;  // nC2 combinations
                    break;
                } 
                else {
                    // Count duplicates on both sides
                    int lcount = 1, rcount = 1;

                    while (left + 1 < right && arr[left] == arr[left + 1]) {
                        lcount++;
                        left++;
                    }
                    while (right - 1 > left && arr[right] == arr[right - 1]) {
                        rcount++;
                        right--;
                    }

                    count += lcount * rcount;
                    left++;
                    right--;
                }
            } 
            else if (sum < target) {
                left++;
            } 
            else {
                right--;
            }
        }

        return count;
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To handle new line after test case count

    while (t--) {
        vector<int> arr;
        int target;
        string input;

        getline(cin, input); // Read array line as string
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> target;
        cin.ignore(); // Skip to the next line

        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
