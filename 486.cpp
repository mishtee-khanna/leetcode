#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = nums;

        for(int i = 2; i <= n; i++){
            for(int j = 0; j <=  n - i; j++){
                int k = j + i - 1;
                dp[j] = max(nums[j] - dp[j + 1], nums[k] - dp[j]);
            }
        }

        return dp[0] >= 0;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 233, 7};

    if (sol.predictTheWinner(nums)) {
        cout << "Player 1 can win!" << endl;
    } else {
        cout << "Player 2 will win." << endl;
    }

    return 0;
}