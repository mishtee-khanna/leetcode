#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1] + 1){
                sum += nums[i];
            }
            else break;
        }

        unordered_set<int> st(nums.begin(), nums.end());

        while(st.count(sum)) sum++;
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 5}; // Example input
    int result = sol.missingInteger(nums);
    cout << "The smallest missing integer is: " << result << endl;
    return 0;
}