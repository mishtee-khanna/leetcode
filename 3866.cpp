#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> counts;
        
        // Step 1: Count the frequency of each number
        for (int num : nums) {
            counts[num]++;
        }
        
        // Step 2: Scan the array from left to right to find the earliest unique even element
        for (int num : nums) {
            if (num % 2 == 0 && counts[num] == 1) {
                return num; // Return immediately to ensure earliest index
            }
        }
        
        // Return -1 if no such unique even integer exists
        return -1;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    vector<int> nums1 = {4, 3, 2, 4, 2, 6};
    cout << "Test 1: " << solver.firstUniqueEven(nums1) << " (Expected: 6)" << endl;
    // Explanation: Even numbers are 4 (appears twice), 2 (appears twice), and 6 (appears once). Earliest unique even is 6.
    
    // Test Case 2
    vector<int> nums2 = {2, 2, 4, 4, 3};
    cout << "Test 2: " << solver.firstUniqueEven(nums2) << " (Expected: -1)" << endl;
    // Explanation: Evens are 2 and 4, but both appear twice. No unique even number exists.

    // Test Case 3
    vector<int> nums3 = {8, 5, 8, 10, 12, 10};
    cout << "Test 3: " << solver.firstUniqueEven(nums3) << " (Expected: 12)" << endl;
    // Explanation: 8 appears twice, 10 appears twice. 12 is even and unique.
    
    return 0;
}