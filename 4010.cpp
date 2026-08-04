#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    long long maxPairStrength(vector<int>& nums) {
        long long max_strength = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                long long g = gcd(nums[i] , nums[j]);
                long long strength =(1LL * nums[i] * nums[j]) / (g * g);
                max_strength = max(max_strength, strength);

            }
        }

        return max_strength;
    }
};

int main(){
    Solution sol;

    // Example usage
    vector<int> nums = {4, 6, 8}; // Input array

    long long maxStrength = sol.maxPairStrength(nums);
    cout << "The maximum pair strength is: " << maxStrength << endl;

    return 0;
}