#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == ch) return false;
            if(board[i][col] == ch) return false;

            int subGridRow = 3 * (row / 3) + i / 3;
            int subGridCol = 3 * (col / 3) + i % 3;
            if(board[subGridRow][subGridCol] == ch) return false;
        }
        return true;
    }
public:
    bool solve(vector<vector<char>>& board){
        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                if(board[r][c] == '.'){
                    for(char ch = '1'; ch <= '9'; ch++){
                        if(isValid(board, r, c, ch)){
                            board[r][c] = ch;
                            if(solve(board)) return true;
                            board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main() {
    Solution sol;

    // Example usage
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '6', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    sol.solveSudoku(board);

    // Print the solved Sudoku board
    for(const auto& row : board){
        for(const auto& cell : row){
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}