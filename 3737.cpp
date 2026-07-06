#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    // A simple Fenwick Tree (Binary Indexed Tree) to count smaller prefix sums efficiently
    vector<int> bit;
    int size;

    void update(int idx, int val) {
        for (; idx < size; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

public:
    int countSubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Prefix sums can range from -n to n. 
        // We shift indices by (n + 1) to keep them positive for the Fenwick Tree.
        size = 2 * n + 2;
        bit.assign(size, 0);
        
        int prefix_sum = 0;
        int total_subarrays = 0;
        
        // Base case: Before processing any elements, prefix sum is 0.
        // Shifted index for 0 is 0 + n + 1
        update(0 + n + 1, 1);
        
        for (int x : nums) {
            // Transform to +1 or -1
            if (x == target) {
                prefix_sum += 1;
            } else {
                prefix_sum -= 1;
            }
            
            // We need to count all previous prefix sums that are strictly less than current prefix_sum
            // Shifted index for current prefix_sum is (prefix_sum + n + 1)
            // We want to query everything up to (prefix_sum + n)
            total_subarrays += query(prefix_sum + n);
            
            // Add the current prefix sum to our tracker
            update(prefix_sum + n + 1, 1);
        }
        
        return total_subarrays;
    }
};

int main() {
    Solution solver;
    
    vector<int> nums1 = {1, 2, 2, 3};
    int target1 = 2;
    cout << "Example 1 Output: " << solver.countSubarrays(nums1, target1) << endl; // Expected: 5

    vector<int> nums2 = {1, 1, 1, 1};
    int target2 = 1;
    cout << "Example 2 Output: " << solver.countSubarrays(nums2, target2) << endl; // Expected: 10

    return 0;
}