#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                candidate = nums[i];
            }

            if(nums[i] == candidate){
                count++;
            }
            else count--;
        }

        return candidate;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3, 2, 3}; // Example input
    int result = sol.majorityElement(nums);
    cout << "The majority element is: " << result << endl;
    return 0;
}