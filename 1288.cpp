#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        int remainingCount = 0;
        int maxEnd = 0;
        
        for (const auto& interval : intervals) {
            if (interval[1] > maxEnd) {
                remainingCount++;
                maxEnd = interval[1];
            }
        }
        
        return remainingCount;
    }
};

int main() {
    Solution solver;

    // Test Case 1: [[1,4],[3,6],[2,8]]
    // Sorted: [1,4], [2,8], [3,6]
    // [1,4] -> keeps (maxEnd = 4)
    // [2,8] -> keeps (maxEnd = 8)
    // [3,6] -> covered by [2,8] because 6 <= 8 (removed)
    // Expected Output: 2
    vector<vector<int>> intervals1 = {{1, 4}, {3, 6}, {2, 8}};
    cout << "Test 1: " << solver.removeCoveredIntervals(intervals1) << " (Expected: 2)" << endl;

    // Test Case 2: [[1,4],[2,3]]
    // Sorted: [1,4], [2,3]
    // [2,3] is completely covered by [1,4]
    // Expected Output: 1
    vector<vector<int>> intervals2 = {{1, 4}, {2, 3}};
    cout << "Test 2: " << solver.removeCoveredIntervals(intervals2) << " (Expected: 1)" << endl;

    return 0;
}