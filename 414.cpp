#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> top3;

        for(int num : nums){
            top3.insert(num);
            if(top3.size() > 3){

                top3.erase(top3.begin());
            } 
        }

        if(top3.size() == 3){
            return *top3.begin();
        }

        return *top3.rbegin();
    }
};

int main(){
    Solution sol;

    vector<int> nums = {3, 2, 1};
    cout << "Third maximum: " << sol.thirdMax(nums) << endl; // Should print 1

    return 0;
}