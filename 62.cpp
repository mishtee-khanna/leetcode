#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long result = 1;
        int totalMoves = m + n - 2;
        int k = min(m - 1, n - 1); // Optimize loop iterations

        for (int i = 1; i <= k; ++i) {
            result = result * (totalMoves - k + i) / i;
        }

        return static_cast<int>(result);
    }
};

int main() {
    Solution sol;

    // Example usage
    int m = 3, n = 7;
    int result = sol.uniquePaths(m, n);
    cout << "Number of unique paths: " << result << endl; // Output: 28

    return 0;
}