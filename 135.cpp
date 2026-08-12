#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> candies(n , 1);

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i - 1]){
                candies[i] = candies[i - 1] + 1;
            }
        }

        for(int i = n - 2; i >= 0; i--){
            if(nums[i] > nums[i + 1]){
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int totalCandies = 0;
        for(int count : candies){
            totalCandies += count;
        }

        return totalCandies;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 0, 2}; // Example input
    int result = sol.candy(nums);
    cout << "The minimum number of candies needed is: " << result << endl;
    return 0;
}