#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (const string& s : strs) {
            int zeros = 0, ones = 0;
            for (char c : s) {
                if (c == '0') zeros++;
                else ones++;
            }
            
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};

int main() {
    Solution solver;

    // Test Case 1: strs = ["10","0001","111001","1","0"], m = 5, n = 3
    // Expected Output: 4 (The subset {"10", "0001", "1", "0"} has 5 '0's and 3 '1's)
    vector<string> strs1 = {"10", "0001", "111001", "1", "0"};
    int m1 = 5, n1 = 3;
    cout << "Test 1: " << solver.findMaxForm(strs1, m1, n1) << " (Expected: 4)" << endl;

    // Test Case 2: strs = ["10","0","1"], m = 1, n = 1
    // Expected Output: 2 (The subset {"0", "1"} has 1 '0' and 1 '1')
    vector<string> strs2 = {"10", "0", "1"};
    int m2 = 1, n2 = 1;
    cout << "Test 2: " << solver.findMaxForm(strs2, m2, n2) << " (Expected: 2)" << endl;

    return 0;
}