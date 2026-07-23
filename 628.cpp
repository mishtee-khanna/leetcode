#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size();

    int product1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
    int product2 = nums[0] * nums[1] * nums[n - 1];

    return max(product1, product2);
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Maximum product of three numbers: " << maximumProduct(nums) << endl;

    return 0;
}
