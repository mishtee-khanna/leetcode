#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> rows(3,0);
        vector<int> cols(3, 0);
        int diag1 = 0;
        int diag2 = 0;

        for(int i = 0; i < moves.size(); i++){
            int r = moves[i][0];
            int c = moves[i][1];

            int val = (i % 2 == 0) ? 1 : -1;

            rows[r] += val;
            cols[c] += val;

            if(r == c) diag1 += val;
            if(r + c == 2) diag2 += val;

            if(abs(rows[r]) == 3 || abs(cols[c]) == 3 || abs(diag1) == 3 || abs(diag2) == 3){
                return (val == 1) ? "A" : "B";
            }
        }

        if(moves.size() == 9) return "Draw";
        return "Pending";

    }
};

int main() {
    Solution sol;

    // Example usage
    vector<vector<int>> moves = {{0,0},{2,0},{1,1},{2,1},{2,2}};
    string result = sol.tictactoe(moves);
    cout << result << endl; // Output: "A"

    return 0;
}