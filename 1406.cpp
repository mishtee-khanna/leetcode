#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(4, 0);

        for(int i = n - 1; i >= 0; i--){
            int maxScore = INT_MIN;
            int currentSum = 0;

            for(int j = 1; j <= 3 && i + j <= n; j++){
                currentSum += stoneValue[i + j - 1];
                int nextDp = dp[(i + j) % 4];
                maxScore = max(maxScore, currentSum - nextDp);
            }

            dp[i % 4] = maxScore;

        }

        int aliceAdvantage = dp[0];
        if(aliceAdvantage > 0) return "Alice";
        if(aliceAdvantage < 0) return "Bob";
        return "Tie";
    }
};

int main() {
    Solution sol;

    // Example usage
    vector<int> stoneValue = {1, 2, 3, 7};
    string result = sol.stoneGameIII(stoneValue);
    cout << result << endl; // Output: "Bob"

    return 0;
}