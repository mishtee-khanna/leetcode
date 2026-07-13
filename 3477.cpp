#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int unplacedCount = 0;
        vector<bool> used(n, false);
        
        for (int fruit : fruits) {
            bool placed = false;
            for (int j = 0; j < n; ++j) {
                if (!used[j] && baskets[j] >= fruit) {
                    used[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                unplacedCount++;
            }
        }
        
        return unplacedCount;
    }
};

int main() {
    Solution solver;

    // Test Case 1
    // fruit 4 goes to basket 5 (idx 1)
    // fruit 2 goes to basket 3 (idx 0)
    // fruit 5 has no available basket >= 5 left (basket 4 is too small) -> Unplaced: 1
    vector<int> fruits1 = {4, 2, 5};
    vector<int> baskets1 = {3, 5, 4};
    cout << "Test 1 Unplaced: " << solver.numOfUnplacedFruits(fruits1, baskets1) << " (Expected: 1)" << endl;

    // Test Case 2
    vector<int> fruits2 = {3, 6, 1};
    vector<int> baskets2 = {6, 4, 7};
    cout << "Test 2 Unplaced: " << solver.numOfUnplacedFruits(fruits2, baskets2) << " (Expected: 0)" << endl;

    return 0;
}