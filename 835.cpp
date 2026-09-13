class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> v1, v2;
        int n = img1.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1) v1.push_back({i , j});
                if(img2[i][j] == 1) v2.push_back({i , j});
            }
        }

        int maxOverlap = 0;
        unordered_map<int, int> translationCounts;

        for(auto& p1 : v1){
            for(auto& p2 : v2){
                int shiftX = p2.first - p1.first + 30;
                int shiftY = p2.second - p1.second + 30;

                int key = shiftX * 100 + shiftY;

                translationCounts[key]++;
                maxOverlap = max(maxOverlap, translationCounts[key]);
            }
        }

        return maxOverlap;
    }
};
