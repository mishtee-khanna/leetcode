#include <iostream>

using namespace std; 

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n > 0) {
            count += n / 5;
            n /= 5;
        }
        return count;
    }
};

int main() {
    Solution solver;
    int n = 25;
    
    int result = solver.trailingZeroes(n);
    
    cout << "Number: " << n << endl;
    cout << "Trailing Zeroes in " << n << "!: " << result << endl; 
    // Expected Output: 6 (Factors from 5, 10, 15, 20 each give one; 25 gives two)

    return 0;
}