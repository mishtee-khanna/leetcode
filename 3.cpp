#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Hash map to store the last seen index of each character
        unordered_map<char, int> charMap;
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            // If the character is found and is inside our current sliding window
            if (charMap.find(s[right]) != charMap.end() && charMap[s[right]] >= left) {
                // Move the left boundary past the previous occurrence of this duplicate
                left = charMap[s[right]] + 1;
            }
            
            // Update or insert the character's most recent position
            charMap[s[right]] = right;
            
            // Calculate and record the maximum length found so far
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    string s1 = "abcabcbb";
    cout << "Test 1: " << solver.lengthOfLongestSubstring(s1) << " (Expected: 3 -> \"abc\")" << endl;
    
    // Test Case 2
    string s2 = "bbbbb";
    cout << "Test 2: " << solver.lengthOfLongestSubstring(s2) << " (Expected: 1 -> \"b\")" << endl;
    
    // Test Case 3
    string s3 = "pwwkew";
    cout << "Test 3: " << solver.lengthOfLongestSubstring(s3) << " (Expected: 3 -> \"wke\")" << endl;
    
    return 0;
}