#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() <= 2) return nums.size();

        int k = 2;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] != nums[k - 2]){
                nums[k] = nums[i];
                k ++;
            }
        }
        return k;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3}; // Example input
    int newLength = sol.removeDuplicates(nums);
    cout << "The new length of the array is: " << newLength << endl;
    cout << "The modified array is: ";
    for(int i = 0; i < newLength; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}