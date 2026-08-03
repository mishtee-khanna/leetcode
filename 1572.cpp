#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            // Add primary diagonal element
            sum += mat[i][i];

            // Add secondary diagonal element if it's not the same as primary
            if (i != n - 1 - i) {
                sum += mat[i][n - 1 - i];
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;

    // Example usage
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int result = sol.diagonalSum(mat);
    cout << "Diagonal Sum: " << result << endl; // Output: Diagonal Sum: 25

    return 0;
}