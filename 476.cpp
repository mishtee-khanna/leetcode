#include <iostream>

using namespace std; 

class Solution {
public:
    int findComplement(int num) {
        // Using unsigned int to prevent potential overflow during bit shifting shifts
        unsigned int mask = 1;
        
        while (mask < num) {
            mask = (mask << 1) | 1;
        }
        
        return num ^ mask;
    }
};

int main() {
    Solution solver;
    int num = 5;
    
    int result = solver.findComplement(num);
    
    cout << "Input Number: " << num << " (Binary: 101)" << endl;
    cout << "Complement:   " << result << " (Binary: 010)" << endl; // Expected Output: 2

    return 0;
}