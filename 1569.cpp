#include <iostream>
#include <vector>

using namespace std;

class Solution {
    long long mod = 1e9 + 7;
    vector<vector<long long>> table;

    long long dfs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        int root = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long left_ways = dfs(left) % mod;
        long long right_ways = dfs(right) % mod;

        int left_size = left.size();
        int right_size = right.size();

        long long ways = (table[n - 1][left_size] * left_ways) % mod;
        ways = (ways * right_ways) % mod;
        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        table.resize(n + 1, vector<long long>(n + 1, 1));
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }
        return (dfs(nums) - 1 + mod) % mod;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 1, 3};
    cout << "Number of ways: " << sol.numOfWays(nums) << endl;
    return 0;
}
