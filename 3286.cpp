#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> maxHealth(m, vector<int>(n, -1));
        priority_queue<pair<int, pair<int, int>>> pq;
        
        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;
        
        pq.push({startHealth, {0, 0}});
        maxHealth[0][0] = startHealth;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int currHealth = top.first;
            int r = top.second.first;
            int c = top.second.second;
            
            if (r == m - 1 && c == n - 1 && currHealth >= 1) {
                return true;
            }
            
            if (currHealth < maxHealth[r][c]) {
                continue;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int nextHealth = currHealth - grid[nr][nc];
                    
                    if (nextHealth >= 1 && nextHealth > maxHealth[nr][nc]) {
                        maxHealth[nr][nc] = nextHealth;
                        pq.push({nextHealth, {nr, nc}});
                    }
                }
            }
        }
        
        return false;
    }
};

int main() {
    Solution solver;

    vector<vector<int>> grid = {
        {0, 1, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    int health = 2;

    bool canWalk = solver.findSafeWalk(grid, health);

    cout << "-----------------------------------" << endl;
    cout << "Can reach destination? " << (canWalk ? "TRUE" : "FALSE") << endl;
    cout << "-----------------------------------" << endl;

    return 0;
}