#include <iostream>
#include <vector>
#include <string>

using namespace std; // Applied per your VS Code workflow preference

class Solution {
private:
    vector<vector<string>> ans;
    vector<bool> cols, diag1, diag2;

    void backtrack(int row, int n, vector<string>& board) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row - col + n] || diag2[row + col]) {
                continue;
            }

            board[row][col] = 'Q';
            cols[col] = diag1[row - col + n] = diag2[row + col] = true;

            backtrack(row + 1, n, board);

            board[row][col] = '.';
            cols[col] = diag1[row - col + n] = diag2[row + col] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        cols.assign(n, false);
        diag1.assign(2 * n, false);
        diag2.assign(2 * n, false);

        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board);
        return ans;
    }
};

int main() {
    Solution solver;
    int n = 4;
    vector<vector<string>> solutions = solver.solveNQueens(n);

    cout << "Total distinct solutions found for n = " << n << ": " << solutions.size() << "\n\n";
    
    for (int i = 0; i < solutions.size(); ++i) {
        cout << "Solution " << i + 1 << ":\n";
        for (const string& row : solutions[i]) {
            cout << row << "\n";
        }
        cout << "\n-----------------\n";
    }

    return 0;
}