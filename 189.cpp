#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; // Essential for VS Code workflow

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return; // Quick return for empty or 1-element arrays
        
        // CRITICAL FIX: Ensure k never exceeds the boundaries of the array
        k = k % n; 
        if (k == 0) return; // No rotation needed
        
        // Step 1: Reverse the whole array
        reverse(nums.begin(), nums.end());
        
        // Step 2: Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        
        // Step 3: Reverse the remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    solver.rotate(nums1, k1);
    cout << "Test 1: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << "(Expected: 5 6 7 1 2 3 4)" << endl;
    
    // Test Case 2
    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    solver.rotate(nums2, k2);
    cout << "Test 2: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << "(Expected: 3 99 -1 -100)" << endl;
    
    return 0;
}