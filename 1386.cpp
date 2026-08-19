#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, vector<bool>> row_blocks;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (row_blocks.find(row) == row_blocks.end()) {
                row_blocks[row] = {false, false, false};
            }

            if (col >= 2 && col <= 5) row_blocks[row][0] = true; 
            if (col >= 4 && col <= 7) row_blocks[row][1] = true; 
            if (col >= 6 && col <= 9) row_blocks[row][2] = true; 
        }
        
        int max_families = (n - row_blocks.size()) * 2;

        for (const auto& pair : row_blocks) {
            bool left_blocked = pair.second[0];
            bool middle_blocked = pair.second[1];
            bool right_blocked = pair.second[2];
            
            if (!left_blocked && !right_blocked) {
                max_families += 2;
            } else if (!left_blocked || !middle_blocked || !right_blocked) {
                max_families += 1;
            }
        }
        
        return max_families;
    }
};

int main() {
    Solution solution;
    int n = 3;
    vector<vector<int>> reservedSeats = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};
    int result = solution.maxNumberOfFamilies(n, reservedSeats);
    cout << "Maximum number of families that can be seated: " << result << endl;
    return 0;
}