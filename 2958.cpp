#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            freq[nums[right]]++;
            
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 1}; // Example input
    int k = 2; // Example k value
    int result = sol.maxSubarrayLength(nums, k);
    cout << "The length of the longest subarray is: " << result << endl;
    return 0;
}