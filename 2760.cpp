#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int maxLength = 0;
        int currentLength = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > threshold) {
                // Condition 3 broken: element exceeds threshold
                currentLength = 0; 
            } else if (currentLength > 0 && (nums[i] % 2 != nums[i - 1] % 2)) {
                // Condition 2 met: Alternating parity within the valid threshold window
                currentLength++; 
            } else if (nums[i] % 2 == 0) {
                // Condition 1 met: Found an even number to start a new window
                currentLength = 1; 
            } else {
                // Odd number that doesn't extend the current alternating pattern
                currentLength = 0;
            }
            
            maxLength = max(maxLength, currentLength);
        }
        
        return maxLength;
    }
};

int main() {
    Solution solver;
    
    // Example 1
    vector<int> nums1 = {3, 2, 5, 4};
    int threshold1 = 5;
    cout << "Test 1: " << solver.longestAlternatingSubarray(nums1, threshold1) 
         << " (Expected: 3 -> Subarray: [2,5,4])" << endl;
         
    // Example 2
    vector<int> nums2 = {1, 2, 3, 4};
    int threshold2 = 2;
    cout << "Test 2: " << solver.longestAlternatingSubarray(nums2, threshold2) 
         << " (Expected: 1 -> Subarray: [2])" << endl;
         
    return 0;
}