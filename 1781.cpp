#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int total_beauty = 0;
        int n = s.length();
        
        // Loop through every possible starting position of a substring
        for (int start = 0; start < n; ++start) {
            vector<int> freq(26, 0); // Tracks frequencies for substrings starting at 'start'
            
            // Expand the substring to the right
            for (int end = start; end < n; ++end) {
                freq[s[end] - 'a']++; // Include the current character
                
                int max_freq = 0;
                int min_freq = n; // Initialize min_freq with a large value
                
                // Find max and min frequencies of characters present in the substring
                for (int i = 0; i < 26; ++i) {
                    if (freq[i] > 0) {
                        max_freq = max(max_freq, freq[i]);
                        min_freq = min(min_freq, freq[i]);
                    }
                }
                
                // Add the beauty of the current substring to the total
                total_beauty += (max_freq - min_freq);
            }
        }
        
        return total_beauty;
    }
};

int main() {
    Solution solver;
    
    // Example 1: "aabcb"
    // Substrings like "aab" have beauty 2 - 1 = 1, "aabcb" has beauty 2 - 1 = 1, etc.
    string s1 = "aabcb";
    cout << "Sum of beauty for \"" << s1 << "\": " << solver.beautySum(s1) << endl; // Expected: 5

    // Example 2: "aabcba"
    string s2 = "aabcba";
    cout << "Sum of beauty for \"" << s2 << "\": " << solver.beautySum(s2) << endl; // Expected: 17

    return 0;
}