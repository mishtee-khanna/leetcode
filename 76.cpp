#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";

        // Map to store the frequency of characters in t
        unordered_map<char, int> targetMap;
        for (char c : t) {
            targetMap[c]++;
        }

        // Number of unique characters in t that need to be present in the window
        int required = targetMap.size();

        // Sliding window pointers
        int left = 0, right = 0;

        // Map to keep track of characters in the current window
        unordered_map<char, int> windowMap;

        // Tracks how many unique characters meet their target frequency in the current window
        int formed = 0;

        // Tracking variables for the minimum window substring
        int minLen = INT_MAX;
        int minLeft = 0;

        while (right < s.length()) {
            char c = s[right];
            windowMap[c]++;

            // If the current character's frequency matches the target frequency
            if (targetMap.find(c) != targetMap.end() && windowMap[c] == targetMap[c]) {
                formed++;
            }

            // Try to contract the window from the left when it becomes valid
            while (left <= right && formed == required) {
                char leftChar = s[left];

                // Save the smallest window boundaries found so far
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                // Remove the character at the 'left' pointer from the window
                windowMap[leftChar]--;
                
                // If removing this character breaks the target criteria, decrement 'formed'
                if (targetMap.find(leftChar) != targetMap.end() && windowMap[leftChar] < targetMap[leftChar]) {
                    formed--;
                }

                left++; // Move the left pointer forward
            }

            right++; // Keep expanding the window to the right
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};

int main() {
    Solution solver;

    // Test Case 1
    string s1 = "ADOBECODEBANC", t1 = "ABC";
    cout << "Test 1: \"" << solver.minWindow(s1, t1) << "\" (Expected: \"BANC\")" << endl;

    // Test Case 2
    string s2 = "a", t2 = "a";
    cout << "Test 2: \"" << solver.minWindow(s2, t2) << "\" (Expected: \"a\")" << endl;

    // Test Case 3
    string s3 = "a", t3 = "aa";
    cout << "Test 3: \"" << solver.minWindow(s3, t3) << "\" (Expected: \"\")" << endl;

    return 0;
}