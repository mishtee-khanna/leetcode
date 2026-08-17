#include<bits/stdc++.h>

using namespace std;

class Solution {
    int memo[501][501];
    int prefix[501];

    int solve(const vector<int>& stoneValue, int left, int right) {
        // Base case: only one stone left, no more divisions possible
        if (left == right) return 0;
        
        // Return already computed result
        if (memo[left][right] != -1) return memo[left][right];

        int max_score = 0;
        
        // Try every possible split point 'i'
        for (int i = left; i < right; ++i) {
            int sum_left = prefix[i + 1] - prefix[left];
            int sum_right = prefix[right + 1] - prefix[i + 1];

            if (sum_left < sum_right) {
                // Bob throws away the right row
                max_score = max(max_score, sum_left + solve(stoneValue, left, i));
            } else if (sum_left > sum_right) {
                // Bob throws away the left row
                max_score = max(max_score, sum_right + solve(stoneValue, i + 1, right));
            } else {
                // Sums are equal, Alice gets to choose the row to keep
                max_score = max(max_score, sum_left + max(solve(stoneValue, left, i), solve(stoneValue, i + 1, right)));
            }
        }

        return memo[left][right] = max_score;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // Initialize memoization table with -1
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                memo[i][j] = -1;
            }
        }

        // Build prefix sum array for O(1) range sum queries
        prefix[0] = 0;
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        return solve(stoneValue, 0, n - 1);
    }
};

int main() {
    Solution solution;
    vector<int> stoneValue = {6, 2, 3, 4, 5, 5};
    int result = solution.stoneGameV(stoneValue);
    cout << "Maximum score Alice can achieve: " << result << endl;
    return 0;
}