#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Calculate the sum of the first 'k' elements
        long long currentSum = 0;
        for (int i = 0; i < k; ++i) {
            currentSum += nums[i];
        }
        
        long long maxSum = currentSum;
        
        // Slide the window across the rest of the array
        for (int i = k; i < nums.size(); ++i) {
            currentSum += nums[i] - nums[i - k]; // Add new right element, drop old left element
            maxSum = max(maxSum, currentSum);
        }
        
        // Return the average as a double
        return (double)maxSum / k;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    cout << "Test 1: " << solver.findMaxAverage(nums1, k1) << " (Expected: 12.75)" << endl;
    
    // Test Case 2
    vector<int> nums2 = {5};
    int k2 = 1;
    cout << "Test 2: " << solver.findMaxAverage(nums2, k2) << " (Expected: 5.00)" << endl;
    
    return 0;
}