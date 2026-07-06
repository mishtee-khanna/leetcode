#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // Helper function to count subarrays with AT MOST k odd numbers
    int countAtMost(const vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        int left = 0;
        int odd_count = 0;
        int subarrays = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            // If the current element is odd, increment our odd counter
            if (nums[right] % 2 != 0) {
                odd_count++;
            }
            
            // Shrink the window from the left if we exceed k odd numbers
            while (odd_count > k) {
                if (nums[left] % 2 != 0) {
                    odd_count--;
                }
                left++;
            }
            
            // The number of valid subarrays ending at 'right' is (right - left + 1)
            subarrays += (right - left + 1);
        }
        
        return subarrays;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};

// Example usage:
int main() {
    Solution solver;
    vector<int> nums1 = {1, 1, 2, 1, 1};
    int k1 = 3;
    cout << "Example 1 Output: " << solver.numberOfSubarrays(nums1, k1) << endl; // Expected: 2

    vector<int> nums2 = {2, 4, 6};
    int k2 = 1;
    cout << "Example 2 Output: " << solver.numberOfSubarrays(nums2, k2) << endl; // Expected: 0

    return 0;
}