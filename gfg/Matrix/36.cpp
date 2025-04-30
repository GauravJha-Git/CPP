// Spirally traversing a matrix
// Difficulty: MediumAccuracy: 35.2%Submissions: 312K+Points: 4
// You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form.

// Examples:

// Input: mat[][] = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
// Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]

// To traverse a matrix in spiral order, you can follow a pattern:

// Traverse the top row left to right,

// then the rightmost column top to bottom,

// then the bottom row right to left,

// then the leftmost column bottom to top,

// and repeat this while narrowing the boundaries.

// code-
#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        vector<int> result;
        int n = mat.size();
        int m = mat[0].size();
        
        int top = 0, bottom = n-1;
        int left = 0, right = m-1;
        
        while(top <= bottom && left<= right){
            for(int i = left; i<=right;i++){
               
                    result.push_back(mat[top][i]);
                }
                top++;
                
                for(int i =top;i<=bottom;i++){
                    result.push_back(mat[i][right]);
                    
                }
                right--;
                
                
                if(top <= bottom){
                    for(int i = right;i>=left;i--){
                        result.push_back(mat[bottom][i]);
                        
                    }
                    bottom--;
                }
                
                if(left<=right){
                    for(int i = bottom; i>=top;i--){
                    result.push_back(mat[i][left]);
                        
                    }
                    left++;
                }
                
        }
            
            return result;
        }
    
};


int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}