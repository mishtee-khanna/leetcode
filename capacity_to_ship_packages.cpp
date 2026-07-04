#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // The ship must be at least as large as the heaviest package
        int low = *max_element(weights.begin(), weights.end());
        // The max capacity needed would be the sum of all packages (shipping all in 1 day)
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int days_needed = 1;
            int current_weight = 0;
            
            for (int weight : weights) {
                // If adding this package exceeds the current mid capacity,
                // we must move to the next day
                if (current_weight + weight > mid) {
                    days_needed++;
                    current_weight = 0;
                }
                current_weight += weight;
            }
            
            // If we managed to ship everything within the allowed days, try a smaller capacity
            if (days_needed <= days) {
                high = mid;
            } else {
                // Otherwise, the capacity is too small; increase it
                low = mid + 1;
            }
        }
        
        return low;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    vector<int> weights1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days1 = 5;
    cout << "Least capacity (Example 1): " << solution.shipWithinDays(weights1, days1) << " (Expected: 15)" << endl;
    
    // Example 2
    vector<int> weights2 = {3, 2, 2, 4, 1, 4};
    int days2 = 3;
    cout << "Least capacity (Example 2): " << solution.shipWithinDays(weights2, days2) << " (Expected: 6)" << endl;
    
    return 0;
}