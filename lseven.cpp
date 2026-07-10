#include<bits/stdc++.h>
using namespace std;

bool lucky_seven(vector<int>& nums){
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i < n - 2; i++){
        sum = nums[i] + nums[i + 1] + nums[i + 2];
        if(sum == 7){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> nums = {1, 2, 4, 3, 5};
    if(lucky_seven(nums)){
        cout << "Lucky seven found!" << endl;
    } else {
        cout << "No lucky seven." << endl;
    }
    return 0;
}