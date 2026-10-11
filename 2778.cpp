
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (n % (i + 1) == 0) {
                sum += nums[i] * nums[i];
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4};
    cout << sol.sumOfSquares(nums) << endl;

    return 0;
}
