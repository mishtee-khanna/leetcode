#include <iostream>
#include <vector>

using namespace std; // Applied per your VS Code workflow preference

class Solution {
private:
    int solutionsCount = 0;
    vector<bool> cols, diag1, diag2;

    void backtrack(int row, int n) {
        if (row == n) {
            solutionsCount++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row - col + n] || diag2[row + col]) {
                continue;
            }

            cols[col] = diag1[row - col + n] = diag2[row + col] = true;

            backtrack(row + 1, n);

            cols[col] = diag1[row - col + n] = diag2[row + col] = false;
        }
    }

public:
    int totalNQueens(int n) {
        solutionsCount = 0;
        cols.assign(n, false);
        diag1.assign(2 * n, false);
        diag2.assign(2 * n, false);

        backtrack(0, n);
        return solutionsCount;
    }
};

int main() {
    Solution solver;

    // Test Case 1: n = 4
    int n1 = 4;
    cout << "Total solutions for " << n1 << "-Queens: " << solver.totalNQueens(n1) << " (Expected: 2)" << endl;

    // Test Case 2: n = 8 (The classic 8x8 chessboard puzzle)
    int n2 = 8;
    cout << "Total solutions for " << n2 << "-Queens: " << solver.totalNQueens(n2) << " (Expected: 92)" << endl;

    return 0;
}