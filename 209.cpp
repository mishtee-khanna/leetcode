#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int currentSum = 0;
        int minLength = INT_MAX;

        for(int right = 0; right < nums.size(); right++){
            currentSum += nums[right];

            while(currentSum >= target){
                minLength = min(minLength, right - left + 1); // * * sliding-window 
                currentSum -= nums[left];
                left++;
            }
        }

        return minLength == INT_MAX ? 0 : minLength;

    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,1,2,4,3}; // Example input
    int target = 7; // Example target
    int result = sol.minSubArrayLen(target, nums);
    cout << "The minimum length of a contiguous subarray is: " << result << endl;
    return 0;
}