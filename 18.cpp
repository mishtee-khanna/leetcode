#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // A valid quadruplet requires at least 4 elements
        if (n < 4) return result;
        
        // 1. Sort the array to easily handle duplicates and use the two-pointer technique
        sort(nums.begin(), nums.end());
        
        // First element pointer
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for the first element by checking backward
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Second element pointer
            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for the second element by checking backward
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                // Two-pointer approach for the remaining two elements
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    // Use long long to prevent potential integer overflow during summation
                    long long currentSum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (currentSum == target) {
                        // Found a valid unique combination
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicate elements for the 'left' pointer forward
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        // Skip duplicate elements for the 'right' pointer backward
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        
                        // Move both pointers inward to evaluate completely new values
                        left++;
                        right--;
                        
                    } else if (currentSum < target) {
                        left++; // Sum is too small, move left pointer to a larger value
                    } else {
                        right--; // Sum is too large, move right pointer to a smaller value
                    }
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1: The identical element case
    vector<int> nums1 = {2, 2, 2, 2, 2};
    int target1 = 8;
    vector<vector<int>> res1 = solver.fourSum(nums1, target1);
    
    cout << "Test Case 1 ([2,2,2,2,2], target = 8):" << endl;
    cout << "Output: [";
    for (const auto& quad : res1) {
        cout << "[";
        for (size_t i = 0; i < quad.size(); ++i) {
            cout << quad[i] << (i < quad.size() - 1 ? "," : "");
        }
        cout << "]";
    }
    cout << "]" << endl << "Expected: [[2,2,2,2]]" << endl << endl;

    // Test Case 2: General mixed case
    vector<int> nums2 = {1, 0, -1, 0, -2, 2};
    int target2 = 0;
    vector<vector<int>> res2 = solver.fourSum(nums2, target2);
    
    cout << "Test Case 2 ([1,0,-1,0,-2,2], target = 0):" << endl;
    cout << "Output: ";
    for (const auto& quad : res2) {
        cout << "[";
        for (size_t i = 0; i < quad.size(); ++i) {
            cout << quad[i] << (i < quad.size() - 1 ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}