#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> counts;
        vector<int> result;
        
        // Step 1: Record the frequencies of elements in nums1
        for (int num : nums1) {
            counts[num]++;
        }
        
        // Step 2: Iterate through nums2 to find matching intersections
        for (int num : nums2) {
            if (counts[num] > 0) {
                result.push_back(num);
                counts[num]--; // Reduce count since we used one instance
            }
        }
        
        return result;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    vector<int> nums1_ex1 = {1, 2, 2, 1};
    vector<int> nums2_ex1 = {2, 2};
    vector<int> res1 = solver.intersect(nums1_ex1, nums2_ex1);
    cout << "Test 1: ";
    for (int n : res1) cout << n << " ";
    cout << "(Expected: 2 2)" << endl;
    
    // Test Case 2
    vector<int> nums1_ex2 = {4, 9, 5};
    vector<int> nums2_ex2 = {9, 4, 9, 8, 4};
    vector<int> res2 = solver.intersect(nums1_ex2, nums2_ex2);
    cout << "Test 2: ";
    for (int n : res2) cout << n << " ";
    cout << "(Expected: 9 4 or 4 9)" << endl;
    
    return 0;
}