#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> suffixSum(n + 1, 0);

        for(int i = n - 1; i >= 0; i--){
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        for(int i = n - 1; i >= 0; i--){
            for(int m = 1; m <= n; m++){
                if(i + 2 * m >= n) dp[i][m] = suffixSum[i];
                else{
                    for(int x = 1; x <= 2 * m; x++){
                        dp[i][m] = max(dp[i][m], suffixSum[i] - dp[i + x][max(m , x)]);
                    }
                }
            }
        }

        return dp[0][1];
    }
};

int main(){
    Solution sol;

    vector<int> piles = {2,7,9,4,4};

    int result = sol.stoneGameII(piles);

    cout << "Maximum stones Alice can get: " << result << endl;

    return 0;
}