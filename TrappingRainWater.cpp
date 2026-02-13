#include <iostream>
#include <vector>
using namespace std;

int maxWater(vector<int> &height) { 
    int n = height.size();
        int l = 0 ,  r = n-1;
        int lmax = 0 , rmax=0;
        int ans = 0;

        while(l<r){

            lmax = max(lmax,height[l]);
            rmax =  max(rmax,height[r]);

            if(lmax<rmax){
                ans+=(lmax-height[l]);
                l++;
            }
            else{
                ans+=(rmax-height[r]);
                r--;
            }

        }

        return ans;
}

int main() {
    vector<int> arr = {2, 1, 5, 3, 1, 0, 4};
    cout << maxWater(arr) << endl;
    return 0;
}