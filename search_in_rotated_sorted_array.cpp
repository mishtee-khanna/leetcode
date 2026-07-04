#include <iostream>
#include <vector>

class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return true;
            }
            
            // Handle duplicates
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
                continue;
            }
            
            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } 
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    std::vector<int> nums1 = {2, 5, 6, 0, 0, 1, 2};
    int target1 = 0;
    std::cout << "Example 1 (Target " << target1 << "): " 
              << (solution.search(nums1, target1) ? "True" : "False") << std::endl;

    // Example 2
    std::vector<int> nums2 = {2, 5, 6, 0, 0, 1, 2};
    int target2 = 3;
    std::cout << "Example 2 (Target " << target2 << "): " 
              << (solution.search(nums2, target2) ? "True" : "False") << std::endl;

    return 0;
}