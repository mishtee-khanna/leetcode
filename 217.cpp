#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            // If the number is already in the set, we found a duplicate
            if (seen.count(num)) {
                return true;
            }
            // Otherwise, add the number to our set
            seen.insert(num);
        }

        // If the loop finishes without finding any duplicates, all numbers are distinct
        return false;
    }
};

int main() {
    Solution solver;

    vector<int> test1 = {1, 2, 3, 1};
    vector<int> test2 = {1, 2, 3, 4};

    cout << boolalpha; // Prints true/false instead of 1/0
    cout << "Test 1 (Expected true): " << solver.containsDuplicate(test1) << endl;
    cout << "Test 2 (Expected false): " << solver.containsDuplicate(test2) << endl;

    return 0;
}