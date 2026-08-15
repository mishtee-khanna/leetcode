#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXOR = 0;
        bool hasNonZero = false;

        for(int num : nums){
            totalXOR ^= num;
            if(num != 0){
                hasNonZero = true;
            }
        }

        if(!hasNonZero) return 0;

        if(totalXOR != 0) return nums.size();

        return nums.size() - 1;
    }
};


int main(){
    Solution sol;
    vector<int> nums1 = {1, 2, 3}; // Example input
    int result1 = sol.longestSubsequence(nums1);
    cout << "The length of the longest subsequence is: " << result1 << endl;

    vector<int> nums2 = {0, 0, 0}; // Another example input
    int result2 = sol.longestSubsequence(nums2);
    cout << "The length of the longest subsequence is: " << result2 << endl;

    vector<int> nums3 = {4, 5, 6, 7}; // Another example input
    int result3 = sol.longestSubsequence(nums3);
    cout << "The length of the longest subsequence is: " << result3 << endl;

    return 0;
}