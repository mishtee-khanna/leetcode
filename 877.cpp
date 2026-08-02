#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = piles[i];
        }

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }

        return dp[0][n - 1] > 0;
    }
};

int main() {
    Solution sol;
    vector<int> piles = {5, 3, 4, 5};

    if (sol.stoneGame(piles)) {
        cout << "Player 1 can win!" << endl;
    } else {
        cout << "Player 2 will win." << endl;
    }

    return 0;
}