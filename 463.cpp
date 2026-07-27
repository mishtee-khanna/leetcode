#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>> grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    perimeter += 4;
                    
                    // Check top neighbor
                    if (i > 0 && grid[i - 1][j] == 1) {
                        perimeter -= 2;
                    }
                    
                    // Check left neighbor
                    if (j > 0 && grid[i][j - 1] == 1) {
                        perimeter -= 2;
                    }
                }
            }
        }
        
        return perimeter;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };
    
    int perimeter = sol.islandPerimeter(grid);
    cout << "The island perimeter is: " << perimeter << endl;
    
    return 0;
}