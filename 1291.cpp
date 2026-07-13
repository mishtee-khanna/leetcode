#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        string digits = "123456789";
        
        int lowLen = to_string(low).length();
        int highLen = to_string(high).length();
        
        // Loop through all possible lengths of numbers
        for (int len = lowLen; len <= highLen; ++len) {
            // Slide a window of size 'len' across the digits string
            for (int start = 0; start <= 9 - len; ++start) {
                string sub = digits.substr(start, len);
                int num = stoi(sub);
                
                // Check if the generated number falls within the target range
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    int low1 = 100, high1 = 300;
    vector<int> res1 = solver.sequentialDigits(low1, high1);
    cout << "Test 1: ";
    for (int x : res1) cout << x << " "; // Expected: 123 234
    cout << endl;
    
    // Test Case 2
    int low2 = 1000, high2 = 13000;
    vector<int> res2 = solver.sequentialDigits(low2, high2);
    cout << "Test 2: ";
    for (int x : res2) cout << x << " "; // Expected: 1234 2345 3456 4567 5678 6789 12345
    cout << endl;
    
    return 0;
}