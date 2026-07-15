#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std; 

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result = "";
        int charCount = 0;
        
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] != '-') {
                if (charCount > 0 && charCount % k == 0) {
                    result.push_back('-');
                }
                result.push_back(toupper(s[i]));
                charCount++;
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution solver;

    // Test Case 1: "5F3Z-2e-9-w", k = 4
    // Expected Output: "5F3Z-2E9W"
    string s1 = "5F3Z-2e-9-w";
    int k1 = 4;
    cout << "Test 1: " << solver.licenseKeyFormatting(s1, k1) << " (Expected: 5F3Z-2E9W)" << endl;

    // Test Case 2: "2-5g-3-J", k = 2
    // Expected Output: "2-5G-3J"
    string s2 = "2-5g-3-J";
    int k2 = 2;
    cout << "Test 2: " << solver.licenseKeyFormatting(s2, k2) << " (Expected: 2-5G-3J)" << endl;

    return 0;
}