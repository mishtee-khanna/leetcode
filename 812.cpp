#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0.0;
        int n = points.size();
        
        // Strictly bound loops to prevent reading garbage memory
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    
                    // Force the coordinates into double immediately
                    double x1 = points[i][0], y1 = points[i][1];
                    double x2 = points[j][0], y2 = points[j][1];
                    double x3 = points[k][0], y3 = points[k][1];
                    
                    // Shoelace formula calculation
                    double currentArea = 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
                    
                    if (currentArea > maxArea) {
                        maxArea = currentArea;
                    }
                }
            }
        }
        
        return maxArea;
    }
};

int main(){
    Solution solver;
    
    // Test Case 1
    vector<vector<int>> points1 = {{0, 0}, {0, 1}, {1, 0}};
    cout << "Test 1 Result: " << solver.largestTriangleArea(points1) << " (Expected: 0.5)" << endl;
    
    // Test Case 2
    vector<vector<int>> points2 = {{0, 0}, {0, 2}, {2, 0}};
    cout << "Test 2 Result: " << solver.largestTriangleArea(points2) << " (Expected: 2.0)" << endl;
    
    // Test Case 3
    vector<vector<int>> points3 = {{1, 0}, {0, 0}, {0, 1}};
    cout << "Test 3 Result: " << solver.largestTriangleArea(points3) << " (Expected: 0.5)" << endl;
    
    return 0;
}