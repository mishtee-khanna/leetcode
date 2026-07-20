#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n - 1];
        
        for (int row = n - 2; row >= 0; --row) {
            for (int i = 0; i <= row; ++i) {
                dp[i] = triangle[row][i] + min(dp[i], dp[i + 1]);
            }
        }
        
        return dp[0];
    }
};

int main() {
    Solution solver;
    vector<vector<int>> triangle = {
        {2},
       {3, 4},
      {6, 5, 7},
     {4, 1, 8, 3}
    };
    
    int result = solver.minimumTotal(triangle);
    
    cout << "Minimum Path Sum: " << result << " (Expected: 11)" << endl;

    return 0;
}