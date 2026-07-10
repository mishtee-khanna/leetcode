#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Extract coordinates for readability
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];
        
        // Check if one rectangle is completely outside the other
        if (x2 <= x3 || // rec1 is completely to the left of rec2
            x1 >= x4 || // rec1 is completely to the right of rec2
            y2 <= y3 || // rec1 is completely below rec2
            y1 >= y4)   // rec1 is completely above rec2
        {
            return false; 
        }
        
        return true;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    vector<int> rec1 = {0, 0, 2, 2};
    vector<int> rec2 = {1, 1, 3, 3};
    cout << "Test 1: " << (solver.isRectangleOverlap(rec1, rec2) ? "true" : "false") << " (Expected: true)" << endl;
    
    // Test Case 2
    vector<int> rec3 = {0, 0, 1, 1};
    vector<int> rec4 = {1, 0, 2, 1};
    cout << "Test 2: " << (solver.isRectangleOverlap(rec3, rec4) ? "true" : "false") << " (Expected: false)" << endl;
    
    return 0;
}