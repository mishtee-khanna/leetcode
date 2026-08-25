#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> contains(201, false);

        for(int element : nums){
            contains[element] = true;
        }

        int result = k;

        while(contains[result]){
            result += k;
        }

        return result;
    }
};

int main(){
    Solution sol;

    int k = 5;
    vector<int> nums = {1,4,7,10,15};

    int result = sol.missingMultiple(nums, k);
    cout << "The missing multiple of " << k << " is : " << result;
    return 0;
}