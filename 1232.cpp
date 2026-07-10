#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if (n <= 2) return true; // 2 points always form a straight line
        
        // Step 1: Get the standard rise and run using the first two points
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int x1 = coordinates[1][0], y1 = coordinates[1][1];
        
        int dx1 = x1 - x0;
        int dy1 = y1 - y0;
        
        // Step 2: Compare every other point against the first point
        for (int i = 2; i < n; ++i) {
            int dx2 = coordinates[i][0] - x0;
            int dy2 = coordinates[i][1] - y0;
            
            // Cross-multiplication check: (dy1 / dx1) == (dy2 / dx2)
            if (dy1 * dx2 != dy2 * dx1) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1: Straight line
    vector<vector<int>> cors1 = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    cout << "Test 1: " << (solver.checkStraightLine(cors1) ? "true" : "false") << " (Expected: true)" << endl;
    
    // Test Case 2: Not a straight line
    vector<vector<int>> cors2 = {{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};
    cout << "Test 2: " << (solver.checkStraightLine(cors2) ? "true" : "false") << " (Expected: false)" << endl;
    
    return 0;
}