#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int memo[105][105][205];
    
    bool dfs(int r, int c, int open_count, vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        if (r >= m || c >= n) return false;
        
        open_count += (grid[r][c] == '(') ? 1 : -1;
        
        if (open_count < 0) return false;
        
        if (r == m - 1 && c == n - 1) return open_count == 0;
        
        if (memo[r][c][open_count] != -1) return memo[r][c][open_count];
        
        bool result = dfs(r + 1, c, open_count, grid) || dfs(r, c + 1, open_count, grid);
        
        return memo[r][c][open_count] = result;
    }
    
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if ((m + n - 1) % 2 != 0) return false;
        
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k <= m + n; k++) {
                    memo[i][j][k] = -1;
                }
            }
        }
        
        return dfs(0, 0, 0, grid);
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<vector<char>> grid = {
        {'(', '(', '('},
        {')', '(', ')'},
        {'(', '(', ')'},
        {'(', '(', ')'}
    };

    bool result = sol.hasValidPath(grid);
    
    cout << "Output: " << (result ? "true" : "false") << endl;

    return 0;
}
