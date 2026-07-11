#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Define binary search boundaries over the virtual 1D array
        int left = 0;
        int right = (m * n) - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Map the 1D 'mid' index back to its 2D coordinates
            int mid_val = matrix[mid / n][mid % n];
            
            if (mid_val == target) {
                return true;
            } else if (mid_val < target) {
                left = mid + 1; // Search the right half
            } else {
                right = mid - 1; // Search the left half
            }
        }
        
        return false;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1 Matrix
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    
    // Test Case 1
    int target1 = 3;
    cout << "Test 1: " << (solver.searchMatrix(matrix, target1) ? "true" : "false") << " (Expected: true)" << endl;
    
    // Test Case 2
    int target2 = 13;
    cout << "Test 2: " << (solver.searchMatrix(matrix, target2) ? "true" : "false") << " (Expected: false)" << endl;
    
    return 0;
}