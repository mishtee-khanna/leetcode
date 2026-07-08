#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        // Base cases handled instantly
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        // Initialize the first three base states
        int t0 = 0, t1 = 1, t2 = 1;
        int nextTerm = 0;

        // Calculate up to n sequentially
        for (int i = 3; i <= n; i++) {
            nextTerm = t0 + t1 + t2; // The sum of the previous three terms
            
            // Shift our window forward by one step
            t0 = t1;
            t1 = t2;
            t2 = nextTerm;
        }

        return t2;
    }
};

int main() {
    Solution solver;
    int n = 4;
    
    // T_0=0, T_1=1, T_2=1, T_3=0+1+1=2, T_4=1+1+2=4
    cout << "The " << n << "-th Tribonacci number is: " << solver.tribonacci(n) << endl; 
    // Expected Output: 4

    return 0;
}