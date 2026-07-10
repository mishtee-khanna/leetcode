#include<bits/stdc++.h>
using namespace std;

vector<int> findTriplet(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());

    int n = nums.size();

    for(int i = 0; i < n - 2; i++){
        int left = i + 1;
        int right = n - 1;

        while(left <  right){
            int sum = nums[i] + nums[left] + nums[right];

            if(sum == target){
                return {nums[i], nums[left], nums[right]};
            }
            else if(sum < target){
                left++;
            }
            else{
                right--;
            }
        }
    }

    return {};
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int target = 10;

    vector<int> result = findTriplet(nums, target);
    if(!result.empty()){
        cout << "Triplet found: ";
        for(int num : result){
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "No triplet found." << endl;
    }

    return 0;

}