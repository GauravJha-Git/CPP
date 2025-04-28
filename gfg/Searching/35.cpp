// Allocate Minimum Pages
// Difficulty: MediumAccuracy: 35.51%Submissions: 262K+Points: 4Average Time: 35m
// You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

// Examples:

// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// [12] and [34, 67, 90] Maximum Pages = 191
// [12, 34] and [67, 90] Maximum Pages = 157
// [12, 34, 67] and [90] Maximum Pages = 113.
// Therefore, the minimum of these cases is 113, which is selected as the output.

// Here's the clear approach:
// First, check if number of books < number of students ⇒ return -1 immediately.

// Next, the minimum possible maximum pages is max(arr) (because at least one book needs to be assigned), and the maximum possible is sum(arr) (one student takes all).

// Binary search between these two (low = max(arr), high = sum(arr)):

// Try a mid value.

// Check: Can we allocate books to k students without any student getting more than mid pages?

// If yes, try a smaller value (move high = mid-1).

// If no, increase pages allowed (move low = mid+1).

// code-

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool isPossible(vector<int> &arr, int k, int mid) {
        int students = 1;
        int pages = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > mid) return false;
            
            if (pages + arr[i] > mid) {
                students++;
                pages = arr[i];
                if (students > k) return false;
            } else {
                pages += arr[i];
            }
        }
        return true;
    }
    
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (n < k) return -1;
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = high;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            
            if (isPossible(arr, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
};


int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

