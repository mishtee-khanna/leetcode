#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>

using namespace std; // Applied per your VS Code workflow preference

class Solution {
private:
    int dp[201][201][201];
    const int MOD = 1e9 + 7;

    int solve(int idx, int g1, int g2, const vector<int>& nums) {
        if (idx == nums.size()) {
            return (g1 > 0 && g1 == g2) ? 1 : 0;
        }

        if (dp[idx][g1][g2] != -1) {
            return dp[idx][g1][g2];
        }

        long long ans = solve(idx + 1, g1, g2, nums);

        int next_g1 = (g1 == 0) ? nums[idx] : std::gcd(g1, nums[idx]);
        ans = (ans + solve(idx + 1, next_g1, g2, nums)) % MOD;

        int next_g2 = (g2 == 0) ? nums[idx] : std::gcd(g2, nums[idx]);
        ans = (ans + solve(idx + 1, g1, next_g2, nums)) % MOD;

        return dp[idx][g1][g2] = ans;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};

int main() {
    Solution solver;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3};
    cout << "Test 1: " << solver.subsequencePairCount(nums1) << " (Expected: 1)" << endl;

    // Test Case 2
    vector<int> nums2 = {10, 20, 30};
    cout << "Test 2: " << solver.subsequencePairCount(nums2) << " (Expected: 10)" << endl;

    return 0;
}