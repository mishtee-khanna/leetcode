#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> freq(26, 0);
        
        for (char c : s) {
            freq[c - 'a']++; 
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i; 
            }
        }
        
        return -1;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1
    string s1 = "leetcode";
    cout << "Test 1: " << solver.firstUniqChar(s1) << " (Expected: 0)" << endl;
    
    // Test Case 2
    string s2 = "loveleetcode";
    cout << "Test 2: " << solver.firstUniqChar(s2) << " (Expected: 2)" << endl;
    
    // Test Case 3
    string s3 = "aabb";
    cout << "Test 3: " << solver.firstUniqChar(s3) << " (Expected: -1)" << endl;
    
    return 0;
}