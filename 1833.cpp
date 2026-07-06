#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Find the maximum cost to define the size of our frequency array
        int max_cost = 0;
        for (int cost : costs) {
            max_cost = max(max_cost, cost);
        }
        
        // Create a frequency array initialized to 0
        vector<int> freq(max_cost + 1, 0);
        for (int cost : costs) {
            freq[cost]++;
        }
        
        int ice_cream_count = 0;
        
        // Iterate through all possible costs starting from the cheapest (1 coin)
        for (int price = 1; price <= max_cost; ++price) {
            // If there are no ice cream bars at this price, skip
            if (freq[price] == 0) continue;
            
            // If we can't even afford a single bar at this price, we can't buy any more
            if (coins < price) break;
            
            // Calculate how many bars of this price we want to buy vs how many we can afford
            int bars_to_buy = min((long long)freq[price], (long long)coins / price);
            
            // Update stats
            ice_cream_count += bars_to_buy;
            coins -= bars_to_buy * price;
        }
        
        return ice_cream_count;
    }
};

int main() {
    Solution solver;
    
    // Example 1
    vector<int> costs1 = {1, 3, 2, 4, 1};
    int coins1 = 7;
    cout << "Example 1 Output: " << solver.maxIceCream(costs1, coins1) << endl; // Expected: 4

    // Example 2
    vector<int> costs2 = {10, 6, 8, 7, 7, 8};
    int coins2 = 5;
    cout << "Example 2 Output: " << solver.maxIceCream(costs2, coins2) << endl; // Expected: 0

    // Example 3
    vector<int> costs3 = {1, 6, 3, 1, 2, 5};
    int coins3 = 20;
    cout << "Example 3 Output: " << solver.maxIceCream(costs3, coins3) << endl; // Expected: 6

    return 0;
}