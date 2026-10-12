#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bit_count(31, 0);
        for (int x : nums) {
            for (int i = 0; i < 31; ++i) {
                if ((x & (1 << i)) != 0) {
                    bit_count[i]++;
                }
            }
        }
        
        long long ans = 0;
        long long mod = 1e9 + 7;
        
        for (int step = 0; step < k; ++step) {
            long long current_num = 0;
            for (int i = 0; i < 31; ++i) {
                if (bit_count[i] > 0) {
                    current_num |= (1 << i);
                    bit_count[i]--;
                }
            }
            ans = (ans + (current_num * current_num) % mod) % mod;
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 6, 5, 8};
    int k = 2;
    cout << "Max Sum: " << sol.maxSum(nums, k) << endl;
    return 0;
}
