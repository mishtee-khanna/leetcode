#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> charCounts;
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            // Add the current character to the window
            charCounts[s[right]]++;
            
            // If any character's count exceeds 2, shrink from the left
            while (charCounts[s[right]] > 2) {
                charCounts[s[left]]--;
                left++;
            }
            
            // Calculate and update the maximum valid window size
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    string s1 = "bcbbbcba";
    cout << "Test 1: " << solver.maximumLengthSubstring(s1) << " (Expected: 4 -> \"bcbb\")" << endl;
    
    // Test Case 2
    string s2 = "aaaa";
    cout << "Test 2: " << solver.maximumLengthSubstring(s2) << " (Expected: 2 -> \"aa\")" << endl;
    
    return 0;
}