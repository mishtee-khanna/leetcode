#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;

        if (target < 0)
            return -1;

        if (target == 0)
            return nums.size();

        int left = 0;
        int currentSum = 0;
        int maxLen = -1;

        for (int right = 0; right < nums.size(); right++) {
            currentSum += nums[right];

            while (currentSum > target && left <= right) {
                currentSum -= nums[left];
                left++;
            }

            if (currentSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen != -1 ? nums.size() - maxLen : -1;
    }
};

int main() {
    Solution solution;

    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter x: ";
    cin >> x;

    int result = solution.minOperations(nums, x);

    cout << "Minimum operations: " << result << endl;

    return 0;
}
