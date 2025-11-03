// User function Template for C++
class Solution {
  public:
    vector<int> getTable(int n) {
        // Write Your Code here
        vector<int> table;
        for(int i = 1; i<11 ; i++){
           table.push_back(n*i); 
        }
        
        return table;
    }
};