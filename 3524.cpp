#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> nextDp(k, 0);
            int currentMod = num % k;

            nextDp[currentMod] += 1;

            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newMod = (r * currentMod) % k;
                    nextDp[newMod] += dp[r];
                }
            }

            for (int r = 0; r < k; r++) {
                result[r] += nextDp[r];
                dp[r] = nextDp[r];
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {2, 3, 4, 5, 6};
    int k = 3;

    Solution sol;
    vector<long long> result = sol.resultArray(nums, k);

    cout << "Result: ";
    for (long long val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
