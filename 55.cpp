#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
            if(maxReach >= n - 1) return true;
        }

        return maxReach >= n - 1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4}; // Example input
    bool result = sol.canJump(nums);
    cout << "Can jump to the last index: " << (result ? "true" : "false") << endl;
    return 0;
}