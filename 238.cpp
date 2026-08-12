#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        int left = 1;
        for(int i = 0; i < n; i++){
            answer[i] = left;
            left *= nums[i];
        }

        int right = 1;
        for(int i = n - 1; i >= 0; i--){
            answer[i] *= right;
            right *= nums[i];
        }

        return answer;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4}; // Example input
    vector<int> result = sol.productExceptSelf(nums);
    cout << "The product of array except self is: ";
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}