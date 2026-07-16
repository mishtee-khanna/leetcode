#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> replaceElements(vector<int> arr){
            int n = arr.size();
            vector<int> ans(n);
            int rightMax = -1;
            for(int i = n - 1; i >= 0; i--){
                ans[i] = rightMax;
                rightMax = max(rightMax, arr[i]);
            }

            return ans;
        }
        
};

int main(){
    Solution solver;
    vector<int> result = solver.replaceElements({23, 34, 544 , 32, 12 , 1 , 98});
    for(int x : result) cout << x << " ";
    cout << endl;
    return 0;
}