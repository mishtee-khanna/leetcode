#include <iostream>

// 1. MOCK API SETUP
const int ACTUAL_FIRST_BAD = 4; 

// This simulates the system API given in the problem
bool isBadVersion(int version) {
    return version >= ACTUAL_FIRST_BAD;
}

// 2. THE SOLUTION FUNCTION

int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    
    while (left < right) {
        // Safe midpoint to prevent integer overflow
        int mid = left + (right - left) / 2; 
        
        if (isBadVersion(mid)) {
            right = mid; // First bad version is at mid or to the left
        } else {
            left = mid + 1; // First bad version is strictly to the right
        }
    }
    
    return left; // 'left' and 'right' converge on the first bad version
}


// 3. MAIN FUNCTION FOR VS CODE
int main() {
    int total_versions = 10;
    
    std::cout << "--- Testing First Bad Version ---" << std::endl;
    std::cout << "Total versions in system: " << total_versions << std::endl;
    std::cout << "Expected first bad version: " << ACTUAL_FIRST_BAD << std::endl;
    
    // Run the algorithm
    int result = firstBadVersion(total_versions);
    
    std::cout << "Algorithm detected first bad version at: " << result << std::endl;
    
    if (result == ACTUAL_FIRST_BAD) {
        std::cout << "Result: SUCCESS! 🎉" << std::endl;
    } else {
        std::cout << "Result: FAILED! ❌" << std::endl;
    }
    
    return 0;
}