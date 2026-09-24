#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int digitSum = 0;
            int temp = nums[i];

            while (temp > 0) {
                digitSum += temp % 10;
                temp /= 10;
            }

            if (digitSum == i)
                return i;
        }

        return -1;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = sol.smallestIndex(nums);

    cout << "Smallest index: " << result << endl;

    return 0;
}
