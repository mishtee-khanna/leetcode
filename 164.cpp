#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        sort(nums.begin(), nums.end());
        int max_dif = 0;
        for(int i = 0; i < n - 1; i++){
            int dif = std::abs(nums[i] - nums[i + 1]);
            max_dif = max(max_dif, dif);
        }

        return max_dif;
    }
};

int main(){
    vector<int> arr1 = {1,2,3,4,5,6};
    Solution solver;

    cout << solver.maximumGap(arr1) << endl;

    vector<int> arr2 = {1, 1000000};
    cout << solver.maximumGap(arr2) << endl;

    return 0;
}