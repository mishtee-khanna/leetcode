#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> concatinateArray(vector<int> arr){
            int n = arr.size();
            vector<int> result(2 * n);

            for(int i = 0; i < n; i++){
                result[i] = result[i + n] = arr[i];
            }

            return result;
        }
};

int main(){
    Solution solver;
    
    vector<int> result = solver.concatinateArray({1 , 2, 1});
    for(int num : result){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}