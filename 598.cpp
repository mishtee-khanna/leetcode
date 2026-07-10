#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        
        int min_row = m;
        int min_col = n;
        
        for (const auto& op : ops) {
            min_row = min(min_row, op[0]);
            min_col = min(min_col, op[1]);
        }
        
        return min_row * min_col;
    }
};

int main() {
    Solution solver;
    
    int m1 = 3, n1 = 3;
    vector<vector<int>> ops1 = {{2, 2}, {3, 3}};
    cout << "Test 1: " << solver.maxCount(m1, n1, ops1) << " (Expected: 4)" << endl;
    
    
    int m2 = 3, n2 = 3;
    vector<vector<int>> ops2 = {{2, 2}, {3, 3}, {3, 3}, {1, 1}, {2, 2}};
    cout << "Test 2: " << solver.maxCount(m2, n2, ops2) << " (Expected: 1)" << endl;
    
    return 0;
}