#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std; // Applied per your VS Code workflow preference

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        
        for (int i = 0; i < n; ++i) {
            unordered_set<int> distinctElements;
            for (int j = i; j < n; ++j) {
                distinctElements.insert(nums[j]);
                int distinctCount = distinctElements.size();
                totalSum += (distinctCount * distinctCount);
            }
        }
        
        return totalSum;
    }
};

int main() {
    Solution solver;

    // Test Case 1: nums = [1, 2, 1]
    // Subarrays: [1], [2], [1], [1,2], [2,1], [1,2,1]
    // Squares:   1^2 + 1^2 + 1^2 + 2^2  + 2^2  + 2^2 = 1 + 1 + 1 + 4 + 4 + 4 = 15
    vector<int> nums1 = {1, 2, 1};
    cout << "Test 1: " << solver.sumCounts(nums1) << " (Expected: 15)" << endl;

    // Test Case 2: nums = [1, 1]
    vector<int> nums2 = {1, 1};
    cout << "Test 2: " << solver.sumCounts(nums2) << " (Expected: 3)" << endl;

    return 0;
}