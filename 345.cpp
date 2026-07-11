#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to check if a character is a vowel
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Move left pointer forward if it's not pointing to a vowel
            while (left < right && !isVowel(s[left])) {
                left++;
            }
            // Move right pointer backward if it's not pointing to a vowel
            while (left < right && !isVowel(s[right])) {
                right--;
            }
            
            // If both are pointing to vowels, swap them
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    string s1 = "IceCreAm";
    cout << "Test 1: " << solver.reverseVowels(s1) << " (Expected: \"AceCreIm\")" << endl;
    
    // Test Case 2
    string s2 = "leetcode";
    cout << "Test 2: " << solver.reverseVowels(s2) << " (Expected: \"leotcede\")" << endl;
    
    return 0;
}