#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    void updateBits(vector<int>& bitCounts, int num, int val) {
        for (int i = 0; i < 32; ++i) {
            if ((num >> i) & 1) bitCounts[i] += val;
        }
    }

    int getOrValue(const vector<int>& bitCounts) {
        int orVal = 0;
        for (int i = 0; i < 32; ++i) {
            if (bitCounts[i] > 0) orVal |= (1 << i);
        }
        return orVal;
    }

public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (k == 0) return 1; // Critical edge case handling

        int n = nums.size(), minLen = INT_MAX, left = 0;
        vector<int> bitCounts(32, 0);

        for (int right = 0; right < n; ++right) {
            updateBits(bitCounts, nums[right], 1);
            
            while (left <= right && getOrValue(bitCounts) >= k) {
                minLen = min(minLen, right - left + 1);
                updateBits(bitCounts, nums[left], -1); // Cleanly undoes bits
                left++;
            }
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};

int main(){
    Solution solver;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 4};
    int k1 = 7;
    cout << "Test 1: " << solver.minimumSubarrayLength(nums1, k1) << " (Expected: 2)" << endl;

    // Test Case 2
    vector<int> nums2 = {1, 2, 4};
    int k2 = 8;
    cout << "Test 2: " << solver.minimumSubarrayLength(nums2, k2) << " (Expected: -1)" << endl;

    // Test Case 3
    vector<int> nums3 = {5, 1, 3};
    int k3 = 5;
    cout << "Test 3: " << solver.minimumSubarrayLength(nums3, k3) << " (Expected: 1)" << endl;

    return 0;
}