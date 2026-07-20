#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        
        while (i < n1 && j < n2) {
            if (nums1[i][0] == nums2[j][0]) {
                result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            } else if (nums1[i][0] < nums2[j][0]) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }
        
        while (i < n1) {
            result.push_back(nums1[i]);
            i++;
        }
        while (j < n2) {
            result.push_back(nums2[j]);
            j++;
        }
        
        return result;
    }
};

int main() {
    Solution solver;
    vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> nums2 = {{1, 4}, {3, 2}, {4, 1}};
    
    vector<vector<int>> result = solver.mergeArrays(nums1, nums2);
    
    cout << "Merged Array:" << endl;
    for (const auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;
    // Expected Output: [1, 6] [2, 3] [3, 2] [4, 6] 

    return 0;
}