#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int expectedSum = n * (n + 1) / 2;

        int actualSum = 0;

        for(int i = 0; i < n; i++){
            actualSum += nums[i];
        }

        return expectedSum - actualSum;
    }
};

int main() {
    Solution sol;

    // Example usage
    vector<int> nums = {3, 0, 1}; // Input array with a missing number

    int missingNum = sol.missingNumber(nums);
    cout << "The missing number is: " << missingNum << endl;

    return 0;
}