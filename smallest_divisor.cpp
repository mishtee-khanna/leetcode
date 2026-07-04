#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int current_sum = 0;
            
            for (int num : nums) {
                // Ceiling division: equivalent to ceil((double)num / mid)
                current_sum += (num + mid - 1) / mid;
            }
            
            // If the sum is within the threshold, try to find a smaller divisor
            if (current_sum <= threshold) {
                high = mid;
            } else {
                // Sum is too large, we need a bigger divisor to reduce the sum
                low = mid + 1;
            }
        }
        
        return low;
    }
};

int main() {
    Solution solution;
    
    // Example 1: nums = [1,2,5,9], threshold = 6 -> Expected Output: 5
    // Explanation: 
    // Divisor = 5 -> 1/5 + 2/5 + 5/5 + 9/5 = 1 + 1 + 1 + 2 = 5 (<= 6)
    vector<int> nums1 = {1, 2, 5, 9};
    int threshold1 = 6;
    cout << "Smallest Divisor (Example 1): " << solution.smallestDivisor(nums1, threshold1) << " (Expected: 5)" << endl;
    
    // Example 2: nums = [44,22,33,11,1], threshold = 5 -> Expected Output: 44
    vector<int> nums2 = {44, 22, 33, 11, 1};
    int threshold2 = 5;
    cout << "Smallest Divisor (Example 2): " << solution.smallestDivisor(nums2, threshold2) << " (Expected: 44)" << endl;
    
    return 0;
}