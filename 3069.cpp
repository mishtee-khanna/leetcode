#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        for(int i = 0; i < nums.size(); i++){
            if(i == 0) arr1.push_back(nums[0]);
            else if(i == 1) arr2.push_back(nums[1]);
            else if(i >= 2){
                if(arr1[arr1.size() - 1] > arr2[arr2.size() - 1]){
                    arr1.push_back(nums[i]);
                }
                else{
                    arr2.push_back(nums[i]);
                }
            }
        }

        int n = arr1.size();
        int m = arr2.size();

        vector<int> result;

        for(int i = 0; i < n; i++){
            result.push_back(arr1[i]);
        }

        for(int i = 0; i < m; i++){
            result.push_back(arr2[i]);
        }

        return result;
    }

};

int main(){
    Solution sol;
    vector<int> nums = {3 , 5 , 23 , 24 , 78, 11, 90};
    vector<int> result = sol.resultArray(nums);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";  
    }

    cout << endl;
    return 0;
}