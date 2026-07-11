#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int rows;
    int cols;

    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int index) {
        // Base Case: If we matched all characters in the word
        if (index == word.length()) {
            return true;
        }

        // Check boundary conditions and character matching
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[index]) {
            return false;
        }

        // Mark the current cell as visited by modifying it in-place
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore all 4 adjacent directions: down, up, right, left
        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);

        // Backtrack: Restore the original character for other search paths
        board[r][c] = temp;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty()) return false;

        rows = board.size();
        cols = board[0].size();

        // Try starting the search from every single cell in the grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main() {
    Solution solver;

    // Test Case Grid
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    // Test Case 1
    string word1 = "ABCCED";
    cout << "Test 1: " << (solver.exist(board, word1) ? "true" : "false") << " (Expected: true)" << endl;

    // Test Case 2
    string word2 = "SEE";
    cout << "Test 2: " << (solver.exist(board, word2) ? "true" : "false") << " (Expected: true)" << endl;

    // Test Case 3
    string word3 = "ABCB";
    cout << "Test 3: " << (solver.exist(board, word3) ? "true" : "false") << " (Expected: false)" << endl;

    return 0;
}