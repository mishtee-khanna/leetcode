#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 1) return false;
        
        // Using long long to prevent integer overflow when squaring 'mid'
        long long left = 1;
        long long right = num;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;
            
            if (square == num) {
                return true;
            } else if (square < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};

int main() {
    Solution solver;
    
    // Test numbers
    int test1 = 16;
    int test2 = 14;
    
    // Enable printing "true" or "false" instead of 1 or 0
    std::cout << std::boolalpha;
    
    std::cout << "Is " << test1 << " a perfect square? " << solver.isPerfectSquare(test1) << " (Expected: true)" << std::endl;
    std::cout << "Is " << test2 << " a perfect square? " << solver.isPerfectSquare(test2) << " (Expected: false)" << std::endl;
    
    return 0;
}