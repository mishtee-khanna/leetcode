#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int> nums) {
        int n = nums.size();
        long long sum = 0;
        long long F = 0;

        // Calculate the sum of all elements and F(0)
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            F += (long long)i * nums[i];
        }

        long long maxF = F;

        // Compute F(1) through F(n-1) using the recurrence relation
        for (int i = 1; i < n; ++i) {
            F = F + sum - (long long)n * nums[n - i];
            maxF = max(maxF, F);
        }

        return maxF;
    }
};

int main(){
    Solution solver;

    cout << solver.maxRotateFunction({4,3,2,6}) << endl;

    cout << solver.maxRotateFunction({100}) << endl;

    return 0;
}