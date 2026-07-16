#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    int gcd(int a, int b){
        if(b  == 0) return a;
        else return(b , a % b);
    }
public:
    int sumOfPairGcd(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        
        int currentMax = nums[0];
        for (int i = 0; i < n; ++i) {
            currentMax = max(currentMax, nums[i]);
            prefixGcd[i] = gcd(nums[i], currentMax);
        }
        
        sort(prefixGcd.begin(), prefixGcd.end());
        
        long long totalSum = 0;
        int left = 0;
        int right = n - 1;
        
        while (left < right) {
            totalSum += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        
        return totalSum;
    }
};

int main() {
    Solution solver;

    // Test Case 1: Even length array
    // nums = [4, 8, 6, 12]
    // Running maxes: [4, 8, 8, 12]
    // prefixGcd: [gcd(4,4), gcd(8,8), gcd(6,8), gcd(12,12)] -> [4, 8, 2, 12]
    // Sorted prefixGcd: [2, 4, 8, 12]
    // Pairs: (2, 12) -> gcd(2,12) = 2; (4, 8) -> gcd(4,8) = 4
    // Expected Sum: 2 + 4 = 6
    vector<int> nums1 = {4, 8, 6, 12};
    cout << "Test 1 (Even Length): " << solver.sumOfPairGcd(nums1) << " (Expected: 6)" << endl;

    // Test Case 2: Odd length array (Middle element ignored)
    // nums = {6, 9, 12}
    // Running maxes: [6, 9, 12]
    // prefixGcd: [gcd(6,6), gcd(9,9), gcd(12,12)] -> [6, 9, 12]
    // Sorted prefixGcd: [6, 9, 12]
    // Pairs: (6, 12) -> gcd(6,12) = 6. 9 is ignored.
    // Expected Sum: 6
    vector<int> nums2 = {6, 9, 12};
    cout << "Test 2 (Odd Length): " << solver.sumOfPairGcd(nums2) << " (Expected: 6)" << endl;

    return 0;
}