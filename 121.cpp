#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int price : prices){
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};

int main(){
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example input
    int result = sol.maxProfit(prices);
    cout << "The maximum profit is: " << result << endl;
    return 0;
}