// Find H-Index
// Given an integer array citations[], where citations[i] is the number of citations a researcher received for the ith paper. The task is to find the H-index.

// H-Index is the largest value such that the researcher has at least H papers that have been cited at least H times.

// Examples:

// Input: citations[] = [3, 0, 5, 3, 0]
// Output: 3
// Explanation: There are at least 3 papers (3, 5, 3) with at least 3 citations.

// To find the H-Index, the idea is:

// Find the maximum number h such that at least h papers have h or more citations.

// ✅ Approach:
// Sort the citations in descending order.

// Traverse the array, and for each index i, check if citations[i] >= i + 1.

// The H-Index is the maximum i + 1 that satisfies the condition.

// code-
#include <bits/stdc++.h>
using namespace std;




// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());
        
        int h=0;
        
        for(int i=0;i<citations.size();i++){
            if(citations[i]>=i+1)
            h=i+1;
            else
                break;
        }
        return h;
    }
};




int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

