#include<bits/stdc++.h>


using namespace std; 

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            if (abs(nums[i]) < abs(closest)) {
                closest = nums[i];
            } else if (abs(nums[i]) == abs(closest)) {
                closest = max(closest, nums[i]);
            }
        }
        
        return closest;
    }
};

int main() {
    Solution solver;

    vector<int> nums1 = {-4, -2, 1, 4, 8};
    cout << "Test 1: " << solver.findClosestNumber(nums1) << " (Expected: 1)" << endl;

    vector<int> nums2 = {2, -1, 1};
    cout << "Test 2: " << solver.findClosestNumber(nums2) << " (Expected: 1)" << endl; // Tie between -1 and 1 -> returns 1

    return 0;
}