#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool checkCompatible(int x, int n, int k){
        // Fixed the operator precedence trap by wrapping (n & x) in parentheses
        return (abs(n - x) <= k) && ((n & x) == 0); 
    }
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;
        
        // Ensure the search window strictly covers positive integers starting from 1
        int low = max(1, n - k);
        int high = n + k;
        
        for (int x = low; x <= high; ++x) {
            if (checkCompatible(x, n, k)) {
                sum += x;
            }
        }
        
        return sum;
    }
};

int main() {
    Solution solver;
    
    // Testing Case 1 from your image (n = 2, k = 3)
    // Valid numbers: 1, 4, 5 -> Sum = 10
    int n1 = 2, k1 = 3;
    cout << "Test Case 1 (n=2, k=3): " << solver.sumOfGoodIntegers(n1, k1) << " (Expected: 10)" << endl;
    
    // Testing another case (n = 5, k = 3)
    // Valid numbers: 2, 8 -> Sum = 10
    int n2 = 5, k2 = 3;
    cout << "Test Case 2 (n=5, k=3): " << solver.sumOfGoodIntegers(n2, k2) << " (Expected: 10)" << endl;
    
    return 0;
}