#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // If we only need to pick 1 student, the difference between highest and lowest is 0
        if (k == 1) return 0;

        // Step 1: Sort the scores
        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;

        // Step 2: Slide a window of size k across the sorted array
        for (int i = 0; i <= nums.size() - k; i++) {
            int currentDiff = nums[i + k - 1] - nums[i];
            minDiff = min(minDiff, currentDiff);
        }

        return minDiff;
    }
};

int main() {
    Solution solver;

    // Example Test Case
    vector<int> scores = {9, 4, 1, 7};
    int k = 2;

    int result = solver.minimumDifference(scores, k);
    cout << "Minimum possible difference: " << result << endl; // Expected output: 2 (from choosing 9 and 7)

    return 0;
}