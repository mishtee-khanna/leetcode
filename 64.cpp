#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 1. Fill the first row (can only come from the left)
        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j - 1];
        }

        // 2. Fill the first column (can only come from above)
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }

        // 3. Fill the rest of the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        // The bottom-right corner now holds the minimum path sum
        return grid[m - 1][n - 1];
    }
};

int main() {
    Solution solver;

    // Example Grid:
    // [1, 3, 1]
    // [1, 5, 1]
    // [4, 2, 1]
    // Optimal Path: 1 -> 3 -> 1 -> 1 -> 1 = 7
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    cout << "Minimum path sum: " << solver.minPathSum(grid) << endl; 
    // Expected Output: 7

    return 0;
}