#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> count;
        for (int num : nums) {
            count[num]++;
        }

        int max_len = 0;

        // 1. Handle the special case of 1s
        if (count.count(1)) {
            int c = count[1];
            // We need an odd number of 1s to form a valid symmetric pattern [1, 1, 1]
            if (c % 2 == 0) {
                max_len = max(max_len, c - 1);
            } else {
                max_len = max(max_len, c);
            }
        }

        // 2. Handle numbers > 1
        for (auto& pair : count) {
            long long x = pair.first;
            if (x == 1) continue;

            int current_len = 0;
            long long current_val = x;

            // Keep squaring the number as long as it exists and has a frequency >= 2
            while (count.count(current_val) && count[current_val] >= 2) {
                current_len += 2;
                
                // Prevent integer overflow before squaring
                if (current_val > 100000) { 
                    current_val = -1; // Flag to break out since next square exceeds constraints (10^9)
                    break;
                }
                current_val = current_val * current_val;
            }

            // The final element (the peak) only needs to appear at least once
            if (current_val != -1 && count.count(current_val) && count[current_val] >= 1) {
                current_len += 1;
            } else {
                // If the peak element doesn't exist or doesn't even have 1 count,
                // we have to backtrack the last element to act as our peak instead.
                current_len -= 1; 
            }

            max_len = max(max_len, current_len);
        }

        return max_len;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {5, 4, 1, 2, 2};
    cout << "Example 1 Output: " << solution.maximumLength(nums1) << endl; // Expected: 3

    vector<int> nums2 = {1, 3, 2, 4};
    cout << "Example 2 Output: " << solution.maximumLength(nums2) << endl; // Expected: 1
    
    return 0;
}