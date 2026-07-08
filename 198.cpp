#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // Fix: Start loop at index 2 to prevent dp[-1] and dp[-2] out-of-bounds access
        // Fix: Change condition to i < n to ensure the last house is included
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
};

int main() {
    Solution solver;
    
    // Test Case: Houses with values [2, 7, 9, 3, 1]
    // Expected Output: 12 (Rob house 1 (2), house 3 (9), and house 5 (1))
    vector<int> houses = {2, 7, 9, 3, 1};
    
    int maxMoney = solver.rob(houses);
    
    cout << "Maximum money that can be robbed: " << maxMoney << endl;
    
    return 0;
}