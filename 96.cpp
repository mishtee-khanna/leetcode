#include <iostream>
#include <vector>

using namespace std; // Applied per your VS Code workflow preference

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int nodes = 2; nodes <= n; ++nodes) {
            for (int root = 1; root <= nodes; ++root) {
                dp[nodes] += dp[root - 1] * dp[nodes - root];
            }
        }
        
        return dp[n];
    }
};

int main() {
    Solution solver;

    // Test Case 1: n = 3
    // Expected Output: 5
    int n1 = 3;
    cout << "Unique BSTs for n = " << n1 << ": " << solver.numTrees(n1) << " (Expected: 5)" << endl;

    // Test Case 2: n = 1
    // Expected Output: 1
    int n2 = 1;
    cout << "Unique BSTs for n = " << n2 << ": " << solver.numTrees(n2) << " (Expected: 1)" << endl;

    return 0;
}