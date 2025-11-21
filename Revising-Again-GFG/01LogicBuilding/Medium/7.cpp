// Cpp program for Pascal's Triangle using Binomial
// Coefficient in O(n^3) and O(1) Space
#include <iostream>
#include <vector>
using namespace std;

int binomialCoeff(int n, int k) {
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

// Function to print first n rows
// of Pascal's Triangle
vector<vector<int>> printPascal(int n) {
    vector<vector<int>> mat;
  
  	// Iterate through every row and
    // print entries in it
    for (int row = 0; row < n; row++) {

        // Every row has number of
        // integers equal to row
        // number
        vector<int> arr;
        for (int i = 0; i <= row; i++)
            arr.push_back(binomialCoeff(row, i));

        mat.push_back(arr);
    }
    return mat;
}

int main() {
  
    int n = 5;
    vector<vector<int>> mat = printPascal(n);
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}