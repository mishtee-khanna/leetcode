#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c); // Max possible value for b
        
        while (left <= right) {
            long long current_sum = (left * left) + (right * right);
            
            if (current_sum == c) {
                return true; // Match found
            } else if (current_sum < c) {
                left++;      // Needs a larger sum
            } else {
                right--;     // Needs a smaller sum
            }
        }
        
        return false;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    int c1 = 5;
    cout << "Test 1: " << (solver.judgeSquareSum(c1) ? "true" : "false") << " (Expected: true)" << endl;
    // Explanation: 1^2 + 2^2 = 1 + 4 = 5
    
    // Test Case 2
    int c2 = 3;
    cout << "Test 2: " << (solver.judgeSquareSum(c2) ? "true" : "false") << " (Expected: false)" << endl;
    
    return 0;
}