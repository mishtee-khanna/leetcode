#include <iostream>

using namespace std; 

// Mocking the LeetCode API internally for local execution
int targetBadVersion = 4;
bool isBadVersion(int version) {
    return version >= targetBadVersion;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid; 
            } else {
                left = mid + 1; 
            }
        }
        return left;
    }
};

int main() {
    Solution solver;
    int totalVersions = 5;
    
    int result = solver.firstBadVersion(totalVersions);
    
    cout << "Total versions in pipeline: " << totalVersions << endl;
    cout << "Actual first defective build set in mock: " << targetBadVersion << endl;
    cout << "Identified First Bad Version via Binary Search: " << result << endl;

    return 0;
}