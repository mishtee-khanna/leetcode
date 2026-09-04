#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return 0;

        vector<int> suffMin(n);
        suffMin[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--){
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        int currentMax = nums[0];

        for(int i = 0; i < n; i++){
            currentMax = max(currentMax, nums[i]);

            if(currentMax - suffMin[i] <= k) return i;
        }

        return -1;
    }

    
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 6, 4, 1, 2};
    int k = 2;
    int result = sol.firstStableIndex(nums, k);
    cout << "First stable index: " << result << endl; // Expected output: 3
    return 0;
}