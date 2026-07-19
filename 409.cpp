#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> charCounts(128, 0);
        for (char c : s) {
            charCounts[c]++;
        }
        
        int length = 0;
        bool hasOdd = false;
        
        for (int count : charCounts) {
            if (count % 2 == 0) {
                length += count;
            } else {
                length += count - 1;
                hasOdd = true;
            }
        }
        
        return hasOdd ? length + 1 : length;
    }
};

int main() {
    Solution solver;
    string s = "abccccdd";
    
    int result = solver.longestPalindrome(s);
    
    cout << "Input String: \"" << s << "\"" << endl;
    cout << "Length of Longest Palindrome: " << result << endl; 
    // Expected Output: 7 (One optimal palindrome configuration could be "dccaccd")

    return 0;
}