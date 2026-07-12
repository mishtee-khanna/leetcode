#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumStrongPairXOR(vector<int>& nums) {
        // 1. Sort the array so that nums[left] is always <= nums[right]
        sort(nums.begin(), nums.end());
        
        int maxXOR = 0;
        int n = nums.size();
        
        // 2. Check every valid pair
        for (int left = 0; left < n; ++left) {
            for (int right = left; right < n; ++right) {
                // Since the array is sorted, this checks if it's a strong pair: y <= 2x
                if (nums[right] <= 2 * nums[left]) {
                    // Calculate XOR and update maximum
                    maxXOR = max(maxXOR, nums[left] ^ nums[right]);
                } else {
                    // Because it's sorted, if nums[right] > 2 * nums[left], 
                    // any element after 'right' will also violate the condition.
                    break;
                }
            }
        }
        
        return maxXOR;
    }
};

int main() {
    Solution solver;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout << "Test 1: " << solver.maximumStrongPairXOR(nums1) << " (Expected: 7)" << endl;

    // Test Case 2
    vector<int> nums2 = {10, 100};
    cout << "Test 2: " << solver.maximumStrongPairXOR(nums2) << " (Expected: 0)" << endl;

    return 0;
}