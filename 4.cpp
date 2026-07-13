#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Step 1: Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        
        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = (m + n + 1) / 2 - i;
            
            // Handle edge cases using INT_MIN and INT_MAX when partitions are empty
            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == m) ? INT_MAX : nums1[i];
            
            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == n) ? INT_MAX : nums2[j];
            
            // Check if we found the correct partition
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Odd combined length
                if ((m + n) % 2 == 1) {
                    return max(maxLeft1, maxLeft2);
                }
                // Even combined length
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            }
            else if (maxLeft1 > minRight2) {
                // i is too large, move left
                high = i - 1;
            }
            else {
                // i is too small, move right
                low = i + 1;
            }
        }
        
        return 0.0;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Test 1: " << solver.findMedianSortedArrays(nums1, nums2) << " (Expected: 2.0)" << endl;
    
    // Test Case 2
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "Test 2: " << solver.findMedianSortedArrays(nums3, nums4) << " (Expected: 2.5)" << endl;
    
    return 0;
}