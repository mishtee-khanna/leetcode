#include <iostream>
#include <cstdint>
#include <bitset>

using namespace std; 

class Solution {
public:
    int32_t reverseBits(int32_t n) {
        uint32_t unsignedNum = static_cast<uint32_t>(n);
        uint32_t result = 0;
        
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            result |= (unsignedNum & 1);
            unsignedNum >>= 1;
        }
        
        return static_cast<int32_t>(result);
    }
};

int main() {
    Solution solver;
    
    // Example: Using -43261596 (which has a clear binary pattern)
    int32_t inputNum = -43261596; 
    int32_t reversedNum = solver.reverseBits(inputNum);
    
    cout << "Original (Decimal): " << inputNum << endl;
    cout << "Original (Binary) : " << bitset<32>(inputNum) << endl;
    
    cout << "Reversed (Binary) : " << bitset<32>(reversedNum) << endl;
    cout << "Reversed (Decimal): " << reversedNum << endl;

    return 0;
}