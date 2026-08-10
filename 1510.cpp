#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1);
        for(int i = 0; i <= n; i++){
            if(!dp[i]){
                for(int j = 1; i + j * j <= n; j++){
                    dp[i + j * j] = true;
                }
                if(dp[n]) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    int n = 7; // Example input
    bool result = sol.winnerSquareGame(n);
    cout << "Can the first player win with n = " << n << "? " << (result ? "Yes" : "No") << endl;
    return 0;
}