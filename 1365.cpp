#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101, 0);

        for(int num : nums){
            count[num]++;
        }

        int sum = 0;
        for(int i = 0; i <= 100; i++){
            int temp = count[i];
            count[i] = sum;
            sum += temp;
        }

        vector<int> result;
        result.reserve(nums.size());

        for(int num : nums){
            result.push_back(count[num]);
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example usage
    vector<int> nums = {8, 1, 2, 2, 3}; // Input array

    vector<int> result = sol.smallerNumbersThanCurrent(nums);

    cout << "The number of smaller elements than the current element for each element is: ";
    for(int count : result){
        cout << count << " ";
    }
    cout << endl;

    return 0;
}