#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper to find the maximum subsequence of a given length from a single vector
    vector<int> maxArray(const vector<int>& nums, int len) {
        vector<int> res;
        int n = nums.size();
        int drop = n - len; // Number of elements we are allowed to drop
        
        for (int num : nums) {
            while (drop > 0 && !res.empty() && res.back() < num) {
                res.pop_back();
                drop--;
            }
            res.push_back(num);
        }
        
        // Trim if the result array is larger than the requested length
        res.resize(len);
        return res;
    }
    
    // Helper to merge two vectors to form the lexicographically largest combination
    vector<int> merge(const vector<int>& max1, const vector<int>& max2) {
        vector<int> res;
        auto it1 = max1.begin(), end1 = max1.end();
        auto it2 = max2.begin(), end2 = max2.end();
        
        while (it1 != end1 || it2 != end2) {
            // Compare the remaining sequences lexicographically
            if (lexicographical_compare(it1, end1, it2, end2)) {
                res.push_back(*it2);
                it2++;
            } else {
                res.push_back(*it1);
                it1++;
            }
        }
        return res;
    }

public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> maxResult;
        
        // Try all valid lengths for the subsequence from nums1
        int start = max(0, k - n);
        int end = min(k, m);
        
        for (int i = start; i <= end; ++i) {
            vector<int> max1 = maxArray(nums1, i);
            vector<int> max2 = maxArray(nums2, k - i);
            vector<int> candidate = merge(max1, max2);
            
            // Keep the lexicographically largest sequence found so far
            if (maxResult.empty() || candidate > maxResult) {
                maxResult = candidate;
            }
        }
        
        return maxResult;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    vector<int> nums1_1 = {3, 4, 6, 5};
    vector<int> nums2_1 = {9, 1, 2, 5, 8, 3};
    int k1 = 5;
    vector<int> result1 = solver.maxNumber(nums1_1, nums2_1, k1);
    cout << "Test 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << "(Expected: 9 8 6 5 3)" << endl;
    
    // Test Case 2
    vector<int> nums1_2 = {6, 7};
    vector<int> nums2_2 = {6, 0, 4};
    int k2 = 5;
    vector<int> result2 = solver.maxNumber(nums1_2, nums2_2, k2);
    cout << "Test 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << "(Expected: 6 7 6 0 4)" << endl;
    
    return 0;
}