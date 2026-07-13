#include<bits/stdc++.h>

using namespace std; 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_ptr = 0;
        int t_ptr = 0;
        
        while (s_ptr < s.length() && t_ptr < t.length()) {
            if (s[s_ptr] == t[t_ptr]) {
                s_ptr++;
            }
            t_ptr++;
        }
        
        return s_ptr == s.length();
    }

    bool isSubsequence1(string s, string t) {  // by dynamic-programming
        int n = t.length();
        
        // dp[i][c] stores the next occurrence index of character 'c' at or after index i
        vector<vector<int>> dp(n + 1, vector<int>(26, -1));
        
        // Build the table backwards
        for (int i = n - 1; i >= 0; --i) {
            for (int c = 0; c < 26; ++c) {
                dp[i][c] = dp[i + 1][c];
            }
            dp[i][t[i] - 'a'] = i;
        }
        
        int current_t_idx = 0;
        for (char ch : s) {
            // 1. Fetch index of the character
            int next_idx = dp[current_t_idx][ch - 'a'];
            
            // 2. CRITICAL FIX: If character doesn't exist down the line, fail immediately
            if (next_idx == -1) {
                return false; 
            }
            
            // 3. Move forward past the matched character position
            current_t_idx = next_idx + 1;
        }
        
        return true;
    }


};

int main() {
    Solution solver;
    
    // Test Case 1
    string s1 = "abc", t1 = "ahbgdc";
    cout << boolalpha; // Prints true/false instead of 1/0
    cout << "Test 1: " << solver.isSubsequence(s1, t1) << " (Expected: true)" << endl;
    
    // Test Case 2
    string s2 = "axc", t2 = "ahbgdc";
    cout << "Test 2: " << solver.isSubsequence1(s2, t2) << " (Expected: false)" << endl;
    
    return 0;
}