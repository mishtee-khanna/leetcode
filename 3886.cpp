#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;

        // desc[i]: number of descents in nums[0..i]
        vector<int> desc(n, 0);

        for (int i = 1; i < n; i++) {
            desc[i] = desc[i - 1] + (nums[i - 1] > nums[i]);
        }

        // premax[i]: maximum element in nums[0..i]
        // sufmin[i]: minimum element in nums[i..n-1]
        vector<int> premax(n), sufmin(n);

        premax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            premax[i] = max(premax[i - 1], nums[i]);
        }

        sufmin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            sufmin[i] = min(sufmin[i + 1], nums[i]);
        }

        // cut[m]: the first m elements contain the m smallest values
        vector<bool> cut(n, true);

        for (int m = 1; m < n; m++) {
            cut[m] = (premax[m - 1] <= sufmin[m]);
        }

        // Check whether nums[l..r] can be sorted by rotation
        auto rotatable = [&](int l, int r) {
            int descents = desc[r] - desc[l];
            bool cyclicDescent = (nums[r] > nums[l]);

            return descents + cyclicDescent <= 1;
        };

        // Check whether all blocks of size k are valid
        auto sortable = [&](int k) {
            for (int l = 0; l < n; l += k) {
                int r = l + k - 1;

                if (!cut[l] || !rotatable(l, r)) {
                    return false;
                }
            }

            return true;
        };

        // Find all divisors of n and count those that are valid
        int answer = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k == 0 && sortable(k)) {
                answer += k;
            }
        }

        return answer;
    }
};

// Test the solution in VS Code
int main() {
    Solution sol;

    vector<int> nums = {3, 1, 2, 4};

    cout << sol.sortableIntegers(nums) << endl;

    return 0;
}
