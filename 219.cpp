#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        
        for (int i = 0; i < nums.size(); i++) {
            // Step 2: If the element is already in our sliding window set, a match is found
            if (window.find(nums[i]) != window.end()) {
                return true;
            }
            
            // Insert current element into the window
            window.insert(nums[i]);
            
            // Step 3: Evict the oldest element if the window size grows past k
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 1};
    int k1 = 3;
    cout << "Test 1: " << (solver.containsNearbyDuplicate(nums1, k1) ? "true" : "false") << " (Expected: true)" << endl;
    
    // Test Case 2
    vector<int> nums2 = {1, 0, 1, 1};
    int k2 = 1;
    cout << "Test 2: " << (solver.containsNearbyDuplicate(nums2, k2) ? "true" : "false") << " (Expected: true)" << endl;
    
    // Test Case 3
    vector<int> nums3 = {1, 2, 3, 1, 2, 3};
    int k3 = 2;
    cout << "Test 3: " << (solver.containsNearbyDuplicate(nums3, k3) ? "true" : "false") << " (Expected: false)" << endl;
    
    return 0;
}