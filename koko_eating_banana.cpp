#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        // Find the maximum element in the piles vector
        int right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            long long total_hours = 0;
            
            for (int pile : piles) {
                // Ceiling division using integer arithmetic: ceil(pile / mid)
                total_hours += (pile + mid - 1) / mid;
            }
            
            // If Koko can finish within h hours, try to slow down (look left)
            if (total_hours <= h) {
                right = mid;
            } else {
                // Too slow, must speed up (look right)
                left = mid + 1;
            }
        }
        
        return left;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    cout << "Min speed (Example 1): " << solution.minEatingSpeed(piles1, h1) << " (Expected: 4)" << endl;
    
    // Example 2
    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    cout << "Min speed (Example 2): " << solution.minEatingSpeed(piles2, h2) << " (Expected: 30)" << endl;
    
    return 0;
}