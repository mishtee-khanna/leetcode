#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    // Mark visited numbers
    for (int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] > 0) {
            nums[index] = -nums[index];
        }
    }

    // Collect missing numbers
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            result.push_back(i + 1);
        }
    }

    return result;
}

int main() {
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " numbers (each between 1 and " << n << "): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> missing = findDisappearedNumbers(nums);

    cout << "Missing numbers: ";
    if (missing.empty()) {
        cout << "None";
    } else {
        for (int num : missing) {
            cout << num << " ";
        }
    }

    cout << endl;

    return 0;
}
